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

'use strict';
var cinecoderAdon = require('bindings')('./Release/cinecoder');

const util = require('util');
const EventEmitter = require('events');


function Decoder (cb) {
  this.decoderAdon = new cinecoderAdon.Decoder(cb);
  EventEmitter.call(this);
}

util.inherits(Decoder, EventEmitter);

Decoder.prototype.setInfo = function(srcTags, dstTags) {
  try {
    return this.decoderAdon.setInfo(srcTags, dstTags);
  } catch (err) {
    this.emit('error', err);
    return 0;
  }
}

Decoder.prototype.decode = function(srcBufArray, dstBuf, cb) {
  try {
    var numQueued = this.decoderAdon.decode(srcBufArray, dstBuf, function(err, resultBytes) {
      cb(err, resultBytes?dstBuf.slice(0,resultBytes):null);
    });
    return numQueued;
  } catch (err) {
    cb(err);
  }
}

Decoder.prototype.quit = function(cb) {
  try {
    this.decoderAdon.quit(function(err, resultBytes) {
      cb(err, resultBytes);
    });
  } catch (err) {
    this.emit('error', err);
  }
}


function Encoder (cb) {
  this.encoderAdon = new cinecoderAdon.Encoder(cb);
  EventEmitter.call(this);
}

util.inherits(Encoder, EventEmitter);

Encoder.prototype.setInfo = function(srcTags, dstTags, duration, bitrate, gopframes) {
  var encodeBitrate = 5000000;
  if (typeof arguments[3] === 'number')
    encodeBitrate = arguments[3];

  var encodeGopFrames = 10 * 60;
  if (typeof arguments[4] === 'number')
    encodeGopFrames = arguments[4];

  try {
    return this.encoderAdon.setInfo(srcTags, dstTags, duration, encodeBitrate, encodeGopFrames);
  } catch (err) {
    this.emit('error', err);
    return 0;
  }
}

Encoder.prototype.encode = function(srcBufArray, dstBuf, cb) {
  try {
    var numQueued = this.encoderAdon.encode(srcBufArray, dstBuf, function(err, resultBytes) {
      cb(err, resultBytes?dstBuf.slice(0,resultBytes):null);
    });
    return numQueued;
  } catch (err) {
    cb(err);
  }
}

Encoder.prototype.quit = function(cb) {
  try {
    this.encoderAdon.quit(function(err, resultBytes) {
      cb(err, resultBytes);
    });
  } catch (err) {
    this.emit('error', err);
  }
}


var cinecoder = {
   Decoder : Decoder,
   Encoder : Encoder
};

module.exports = cinecoder;
