const { HdrHistogram, HdrHistogramIterator } = require('bindings')('binding');
const isNumber = value => typeof value === 'number' && value === value && value !== Infinity && value !== -Infinity

class Histogram extends HdrHistogram {
    constructor(min, max, sigDigits) {
        super(min, max, sigDigits);
    }

    record (value, count) {
        if (isNumber(value)) {
          if (typeof count === 'undefined') {
            return super.recordValue(value);
          } else {
            return super.recordValues(value, count);
          }
        } else {
            return false;
        }
    }

    encode () {
        return super.getEncoded();
    }

    static decode (encoded) {
        let histogram = new Histogram (1, 10); // the values here are immaterial
        histogram.setEncoded(encoded);
        return histogram;
    }

    percentile (value) {
        if (!isNumber(value)) {
            throw(Error("No percentile specified"));
        } else if (value <= 0 || value > 100) {
            throw(Error("percentile must be > 0 and <= 100"));
        } else {
            return super.percentile(value);
        }
    }

    percentiles () {
        let result = [];
        let iter = new HdrHistogramIterator(this);
        iter.initPercentile(1);
        while (iter.next()) {
            result.push ({ percentile: iter.getPercentile(), value: iter.getValue() });
        }
        return result;
    }

    reset() {
        super.reset();
        return this;
    }

    add (histogram, expected_interval) {
        if (typeof expected_interval === 'undefined') {
            return super.add(histogram)
        } else {
            return super.addWhileCorrectingForCoordinatedOmission(histogram, expected_interval)
        }
    }

    highestEquivalentValue (value) {
        return super.nextNonEquivalentValue(value) - 1;
    }

}

module.exports.Histogram = Histogram;
