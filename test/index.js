const { HdrHistogram, HdrHistogramIterator } = require('bindings')('binding');

let h = new HdrHistogram (1, 100, 2);
let i = new HdrHistogramIterator ();
let j = 0;
console.log("Life is good.");