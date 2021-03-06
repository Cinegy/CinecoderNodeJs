# CinecoderNodeJs

CinecoderNodeJs is a [Node.js](http://nodejs.org/) [addon](http://nodejs.org/api/addons.html) using Javascript and C++ to implement async processing for media encoding, decoding and processing. All the node wrapping and testing functions were made by the nice folks at StreamPunk Media, and passed to Cinegy for us to add our interfaces to get the Cinecoder binary to work with the addon. Complain to Cinegy first if we break something going forward before bothering the StreamPunk team!

## Installation

Install [Node.js](http://nodejs.org/) for your platform. This software has been developed against the long term stable (LTS) 12 release.

This module has native C++ files that are compiled with node-gyp. To use the module, you many need to install a C++ compiler and python v2.x on your system. On Windows, node may need to be configured with:

    npm config set msvs_version 2015 --global

CinecoderNodeJs is designed to be `require`d to use from your own application to provide async processing.

    npm install --save cinecodernodejs

Node.js addons use [libuv](http://libuv.org/) which by default supports up to 4 async threads in a threadpool for activities such as file I/O. These same threads are used by cinecoder and if you wish to use a number of the functions in one Node.js process then you will need to set the environment variable UV_THREADPOOL_SIZE to a suitable number before the first use of the libuv threadpool.

## Using cinecodernodejs

To use cinecoder in your own application, `require` the module then create and use workers as required.  The processing functions follow a standard pattern as shown in the example code below.

```javascript
let cinecoder = require('cinecodernodejs');

let encoder = new cinecoder.Encoder(() => {
  // encoder has successfully exited
});
encoder.on('error', err => {
  // handle error
});

// send the parameters for the function (these differ by function), return value is suggested result buffer size
let dstBufLen = encoder.setInfo(srcTags, dstTags, duration, encodeTags);

// async request for processing to be done.
encoder.encode(srcBuf, Buffer.alloc(dstBufLen), (err, result) => {
  if (err) {
    // handle error
  } else if (result) {
    // result is a JS buffer containing the encoded data. Note it may be a different size to dstBuf
  }
});

// async request for the processing thread to quit when it has finished the latest request
encoder.quit(() => {
});
```
## Status, support and further development

We use AppVeyor to run integration tests, you can see the results of the last master branch build below:

![Build status](https://ci.appveyor.com/api/projects/status/nmy0sb6yceb8ub9p/branch/master?svg=true)

See the project on AppVeyor here: https://ci.appveyor.com/project/cinegy/cinecodernodejs

## License

This software is released under the Apache 2.0 license.

Copyright 2016 Streampunk Media Ltd.
Copyright 2017,2020 Cinegy GmbH.
