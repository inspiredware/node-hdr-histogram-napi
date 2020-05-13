const { HdrHistogram, HdrHistogramIterator } = require('bindings')('binding');
const isNumber = value => typeof value === 'number' && value === value && value !== Infinity && value !== -Infinity

class Histogram extends HdrHistogram {
    constructor(min, max, sigDigits) {
        super(min, max, sigDigits);
    }

    record (value) {
        // TODO: this should be implemented in the binding toolkit
        if (isNumber(value)) {
            return super.record(value);
        } else {
            return false;
        }
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

    reset() {
        super.reset();
        return this;
    }
}

module.exports.Histogram = Histogram;
