const { HdrHistogram, HdrHistogramIterator } = require('bindings')('binding');
const { Histogram } = require('../Histogram.js');

let h = new HdrHistogram (1, 100, 2);
let i = new HdrHistogramIterator (h);
let j = new Histogram (1, 100, 2);
let k = 0;