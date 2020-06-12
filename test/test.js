'use strict'

const test = require('tap').test
const { HdrHistogram, HdrHistogramIterator } = require('bindings')('binding');
const { Histogram } = require('../Histogram.js');

test('create an histogram', (t) => {
  t.doesNotThrow(() => new Histogram(1, 100))
  t.end()
})

test('create an histogram with a constructor', (t) => {
  t.doesNotThrow(() => new Histogram(1, 100))
  t.end()
})

test('create an histogram arguments checks', (t) => {
  t.throws(() => new Histogram(-1, 100))
  t.throws(() => new Histogram(0, 100))
  t.throws(() => new Histogram(1, 100, 20))
  t.throws(() => new Histogram(1, 100, 0))
  t.throws(() => new Histogram(1, 100, 6))
  for (let i = 1; i < 5; i++) {
    t.doesNotThrow(() => new Histogram(1, 100, i))
  }
  t.end()
})

test('record values in an histogram', (t) => {
  const instance = new Histogram(1, 100)
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.end()
})

test('recording a non-value returns false', (t) => {
  const instance = new Histogram(1, 100)
  t.notOk(instance.record())
  t.notOk(instance.record(-42))
  t.end()
})

test('stdev, mean, min, max', (t) => {
  const instance = new Histogram(1, 100)
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.equal(instance.min(), 42, 'min is available')
  t.equal(instance.max(), 45, 'max is available')
  t.equal(instance.mean(), 43.5, 'mean is available')
  t.equal(instance.stddev(), 1.5, 'stdev is available')
  t.end()
})

test('lowestTrackableValue, highestTrackableValue, significantFigures, unitMagnitude, totalCount', (t) => {
  const instance = new Histogram(1, 100)
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.equal(instance.lowestTrackableValue, 1, 'lowestTrackableValue is available')
  t.equal(instance.highestTrackableValue, 100, 'highestTrackableValue is available')
  t.equal(instance.significantFigures, 3, 'significantFigures is available')
  t.equal(instance.unitMagnitude, 0, 'unitMagnitude is available')
  t.equal(instance.totalCount, 2, 'totalCount is available')
  t.end()
})

test('percentile', (t) => {
  const instance = new Histogram(1, 100)
  t.ok(instance.record(42))
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.equal(instance.percentile(10), 42, 'percentile match')
  t.equal(instance.percentile(99), 45, 'percentile match')
  t.equal(instance.percentile(100), 45, 'percentile match')
  t.end()
})

test('wrong percentile', (t) => {
  const instance = new Histogram(1, 100)
  t.ok(instance.record(42))
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.throws(() => instance.percentile(), 'no percentile throws')
  t.throws(() => instance.percentile(101), 'percentile > 100 throws')
  t.throws(() => instance.percentile(0), 'percentile == 0 throws')
  t.throws(() => instance.percentile(-1), 'percentile < 0 throws')
  t.end()
})

test('encode/decode', (t) => {
  const instance = new Histogram(1, 100)
  t.ok(instance.record(42))
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  const instance2 = Histogram.decode(instance.encode())
  t.equal(instance2.percentile(10), 42, 'percentile match')
  t.equal(instance2.percentile(99), 45, 'percentile match')
  t.end()
})

test('fail decode', (t) => {
  t.throws(() => Histogram.decode())
  t.throws(() => Histogram.decode('hello'))
  t.throws(() => Histogram.decode({}))
  t.throws(() => Histogram.decode(42))
  t.end()
})

test('percentiles', (t) => {
  const instance = new Histogram(1, 100)
  t.deepEqual(instance.percentiles(), [{
    percentile: 100,
    value: 0
  }], 'empty percentiles has 0 till 100%')
  t.ok(instance.record(42))
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.deepEqual(instance.percentiles(), [{
    percentile: 0,
    value: 42
  }, {
    percentile: 50,
    value: 42
  }, {
    percentile: 75,
    value: 45
  }, {
    percentile: 100,
    value: 45
  }], 'percentiles matches')
  t.end()
})

test('add', (t) => {
  const instance1 = new Histogram(1, 100)
  t.ok(instance1.record(1))
  t.ok(instance1.record(2))
  t.ok(instance1.record(3))
  t.equal(instance1.mean(), 2, 'mean is correct')
  const instance2 = new Histogram(1, 100)
  t.ok(instance2.record(5))
  t.ok(instance2.record(6))
  t.ok(instance2.record(7))
  t.equal(instance2.mean(), 6, 'mean is correct')
  instance1.add(instance2)
  let x = instance1.mean()
  t.equal(instance1.mean(), 4, 'mean is correct')
  t.end()
})

test('support >2e9', (t) => {
  const recordValue = 4 * 1e9
  const instance = new Histogram(1, recordValue)
  var compare = (a, b) => {
    var diff = Math.abs(a - b)
    // hdr_min and hdr_max do not return precise data, even before
    // conversion to double.
    if (diff < 1e-3 * Math.min(Math.abs(a), Math.abs(b))) {
      return true
    } else {
      console.error(`Mismatch! Got ${a}, expected ${b}!`)
      return false
    }
  }
  t.ok(instance.record(recordValue))
  t.ok(compare(instance.min(), recordValue), 'min match')
  t.ok(compare(instance.max(), recordValue), 'max match')
  t.end()
})

test('reset histogram', (t) => {
  const instance = new Histogram(1, 100)
  t.equal(instance.min(), 9223372036854776000, 'min is setup')
  t.equal(instance.max(), 0, 'max is setup')
  t.ok(instance.record(42))
  t.ok(instance.record(45))
  t.equal(instance.min(), 42, 'min is correct before reset')
  t.equal(instance.max(), 45, 'max is correct before reset')
  t.equal(instance.mean(), 43.5, 'mean is correct before reset')
  t.equal(instance.stddev(), 1.5, 'stdev is correct before reset')
  t.ok(instance.reset())
  t.equal(instance.min(), 9223372036854776000, 'min is reset')
  t.equal(instance.max(), 0, 'max is reset')
  t.ok(instance.record(52))
  t.ok(instance.record(55))
  t.equal(instance.min(), 52, 'min is correct after reset')
  t.equal(instance.max(), 55, 'max is correct after reset')
  t.equal(instance.mean(), 53.5, 'mean is correct after reset')
  t.equal(instance.stddev(), 1.5, 'stdev is correct after reset')
  // test to ensure maintains ref to self when returning after reset
  var resetInstance = instance.reset()
  t.equal(instance, resetInstance)
  t.end()
})
