/* Copyright 2016 Streampunk Media Ltd.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

var fs = require('fs');
var test = require('tape');
var cinecoder = require('../../cinecodernodejs');

function makeUYVY10Buf(width, height) {
  var pitchBytes = width * 4;
  var buf = Buffer.alloc(pitchBytes * height);  
  var yOff = 0;
  for (var y=0; y<height; ++y) {
    var xOff = 0;
    for (var x=0; x<width; x+=2) {
      buf.writeUInt16LE(0x0200, yOff + xOff);
      buf.writeUInt16LE(0x0040, yOff + xOff + 2);
      buf.writeUInt16LE(0x0200, yOff + xOff + 4);
      buf.writeUInt16LE(0x0040, yOff + xOff + 6);
      xOff += 8;
    }
    yOff += pitchBytes;
  }   
  return buf;
}


function makeTags(width, height, packing, encodingName, interlace) {
  this.tags = [];
  this.tags["format"] = [ "video" ];
  this.tags["width"] = [ `${width}` ];
  this.tags["height"] = [ `${height}` ];
  this.tags["packing"] = [ packing ];
  this.tags["encodingName"] = [ encodingName ];
  this.tags["interlace"] = [ `${interlace}` ];
  return tags;
}


var duration = Buffer.alloc(8);
duration.writeUIntBE(1, 0, 4);
duration.writeUIntBE(25, 4, 4);

function encodeTest(description, numTests, onErr, fn) {
  test(description, function (t) {
    t.plan(numTests);
    var encoder = new cinecoder.Encoder(function() {});
    encoder.on('error', function(err) {
      onErr(t, err);
    });

    fn(t, encoder, function() {
      encoder.quit(function() {});
    });
  });
};

function decodeTest(description, numTests, onErr, fn) {
  test(description, function (t) {
    t.plan(numTests);
    var decoder = new cinecoder.Decoder(function() {});
    decoder.on('error', function(err) {
      onErr(t, err);
    });

    fn(t, decoder, function() {
      decoder.quit(function() {});
    });
  });
};

function badDims() {
  var srcTags = makeTags(1280, 720, 'UYVY10', 'raw', 0);
  var dstTags = makeTags(21, 0, 'AVCi50', 'AVCi50', 0);
  encoder.setInfo(srcTags, dstTags);
}

function badFmt() {
  var srcTags = makeTags(1920, 1080, 'YUV422P10', 'raw', 0);
  var dstTags = makeTags(1920, 1080, 'AVCi50', 'AVCi50', 0);
  encoder.setInfo(srcTags, dstTags, duration);
}

encodeTest('Handling bad image dimensions', 1,
  function (t, err) {
    t.ok(err, 'emits error');
  }, 
  function (t, encoder, done) {
    t.throws(badDims);
    done();
  });

encodeTest('Handling bad image format', 1,
  function (t, err) {
    t.ok(err, 'emits error');
  }, 
  function (t, encoder, done) {
    t.throws(badFmt);
    done();
  });

encodeTest('Starting up an encoder', 1,
  function (t, err) {
    t.notOk(err, 'no error expected');
  }, 
  function (t, encoder, done) {
    var dstWidth = 1920; 
    var dstHeight = 1080; 
    var srcTags = makeTags(1920, 1080, 'UYVY10', 'raw', 0);
    var dstTags = makeTags(dstWidth, dstHeight, 'AVCi50', 'AVCi50', 0);
    var dstBufLen = encoder.setInfo(srcTags, dstTags, duration);
    var numBytesExpected = 600000;
    t.equal(dstBufLen, numBytesExpected, 'buffer size calculation matches the expected value');
    done();
  });

encodeTest('Performing AVCi encoding', 1,
  function (t, err) {
    t.notOk(err, 'no error expected');
  }, 
  function (t, encoder, done) {
    var srcWidth = 1920;
    var srcHeight = 1080;
    var srcFormat = 'UYVY10';
    var dstWidth = 1920; 
    var dstHeight = 1080; 
    var dstFormat = 'AVCi50';
    var srcTags = makeTags(srcWidth, srcHeight, srcFormat, 'raw', 0);
    var dstTags = makeTags(dstWidth, dstHeight, dstFormat, dstFormat, 0);
    var srcBuf = makeUYVY10Buf(srcWidth, srcHeight);
    var dstBufLen = encoder.setInfo(srcTags, dstTags, duration);
    var dstBuf = Buffer.alloc(dstBufLen);
    encoder.encode(srcBuf, dstBuf, function(err, result) {
      t.notOk(err, 'no error expected');
      fs.writeFileSync("avci.raw", result);
      // todo: check for valid bitstream...
      done();
    });
  });

decodeTest('Performing AVCi decoding', 2,
  function (t, err) {
    t.notOk(err, 'no error expected');
  }, 
  function (t, decoder, done) {
    var srcWidth = 1920;
    var srcHeight = 1080;
    var srcFormat = 'AVCi50';
    var dstWidth = 1920; 
    var dstHeight = 1080; 
    var dstFormat = 'UYVY10';
    var srcTags = makeTags(srcWidth, srcHeight, srcFormat, srcFormat, 0);
    var dstTags = makeTags(dstWidth, dstHeight, dstFormat, 'raw', 0);
    var srcBuf = fs.readFileSync("avci.raw");
    t.ok(srcBuf, 'read encoded file');
    var dstBufLen = decoder.setInfo(srcTags, dstTags, duration);
    var dstBuf = Buffer.alloc(dstBufLen);
    decoder.decode(srcBuf, dstBuf, function(err, result) {
      t.notOk(err, 'no error expected');
      // todo: check for valid bitstream...
      // var origBuf = makeUYVY10Buf(srcWidth * 3 / 4, srcHeight);
      // t.deepEqual(result, origBuf, "matches expected result");
      done();
    });
  });

encodeTest('Handling an undefined source buffer', 1,
  function (t, err) {
    t.notOk(err, 'no error expected');
  }, 
  function (t, encoder, done) {
    var srcWidth = 1920;
    var srcHeight = 1080;
    var srcFormat = 'UYVY10';
    var dstWidth = 1920; 
    var dstHeight = 1080; 
    var dstFormat = 'AVCi50';
    var srcTags = makeTags(srcWidth, srcHeight, srcFormat, 'raw', 0);
    var dstTags = makeTags(dstWidth, dstHeight, dstFormat, dstFormat, 0);
    var dstBufLen = encoder.setInfo(srcTags, dstTags, duration);
    var srcBuf;
    var dstBuf = Buffer.alloc(dstBufLen);
    encoder.encode(srcBuf, dstBuf, function(err, result) {
      t.ok(err, 'should return error');
      done();
    });
  });

encodeTest('Handling an undefined destination buffer', 1,
  function (t, err) {
    t.notOk(err, 'no error expected');
  }, 
  function (t, encoder, done) {
    var srcWidth = 1920;
    var srcHeight = 1080;
    var srcFormat = 'UYVY10';
    var dstWidth = 1920; 
    var dstHeight = 1080; 
    var dstFormat = 'AVCi50';
    var srcTags = makeTags(srcWidth, srcHeight, srcFormat, 'raw', 0);
    var dstTags = makeTags(dstWidth, dstHeight, dstFormat, dstFormat, 0);
    var srcBuf = makeUYVY10Buf(srcWidth, srcHeight);
    var dstBufLen = encoder.setInfo(srcTags, dstTags, duration);
    var dstBuf;
    encoder.encode(srcBuf, dstBuf, function(err, result) {
      t.ok(err, 'should return error');
      done();
    });
  });
