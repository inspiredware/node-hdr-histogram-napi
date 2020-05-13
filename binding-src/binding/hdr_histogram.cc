// 2020-05-12T17:52:41.772-07:00 binding hdr_histogram.c (GenerateDefinitions)
// Created by the inspiredware automated binding generator — www.inspiredware.com

#include "hdr_histogram.h"
#include "napi-ingress.h"

extern "C" {
}
// pseudoClass HdrHistogram definition begin //

HdrHistogram::HdrHistogram (const Napi::CallbackInfo& info)
: Napi::ObjectWrap<HdrHistogram> (info)
, histogram (NULL)
{
  Napi::Env env = info.Env();
  long long min = getNumber<long long> (info, 0);
  long long max = getNumber<long long> (info, 1);
  int sigFigures = info[2].IsUndefined() ? 3 : getNumber<int> (info, 2);
  int status = hdr_init (min, max, sigFigures, &histogram);
  if (status) { // TODO: correctly implement error handling
    Napi::Error::New(env, "hdr_init failed.").ThrowAsJavaScriptException();
  }
}

HdrHistogram::~HdrHistogram () {
  hdr_close (histogram); // frees memory
}

Napi::Value HdrHistogram::resetInternalCounters (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  hdr_reset_internal_counters (histogram);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::close (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  hdr_close (histogram);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::reset (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  hdr_reset (histogram);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::getMemorySize (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  unsigned long retVal = hdr_get_memory_size (histogram);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::record (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  _Bool retVal = hdr_record_value (histogram, value);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  _Bool retVal = hdr_record_value_atomic (histogram, value);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordValues (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long count = getNumber<long long> (info, 1);
  _Bool retVal = hdr_record_values (histogram, value, count);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordValuesAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long count = getNumber<long long> (info, 1);
  _Bool retVal = hdr_record_values_atomic (histogram, value, count);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordCorrectedValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long expected_interval = getNumber<long long> (info, 1);
  _Bool retVal = hdr_record_corrected_value (histogram, value, expected_interval);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordCorrectedValueAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long expected_interval = getNumber<long long> (info, 1);
  _Bool retVal = hdr_record_corrected_value_atomic (histogram, value, expected_interval);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordCorrectedValues (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long count = getNumber<long long> (info, 1);
  long long expected_interval = getNumber<long long> (info, 2);
  _Bool retVal = hdr_record_corrected_values (histogram, value, count, expected_interval);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::recordCorrectedValuesAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long count = getNumber<long long> (info, 1);
  long long expected_interval = getNumber<long long> (info, 2);
  _Bool retVal = hdr_record_corrected_values_atomic (histogram, value, count, expected_interval);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::add (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long retVal = hdr_add (histogram, histogram);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::max (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long retVal = hdr_max (histogram);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::min (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long retVal = hdr_min (histogram);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::percentile (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  double percentile = getNumber<double> (info, 0);
  long long retVal = hdr_value_at_percentile (histogram, percentile);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::mean (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  double retVal = hdr_mean (histogram);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::stddev (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  double retVal = hdr_stddev (histogram);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::valuesAreEquivalent (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long a = getNumber<long long> (info, 0);
  long long b = getNumber<long long> (info, 1);
  _Bool retVal = hdr_values_are_equivalent (histogram, a, b);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::lowestEquivalentValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long retVal = hdr_lowest_equivalent_value (histogram, value);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::countAtValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value = getNumber<long long> (info, 0);
  long long retVal = hdr_count_at_value (histogram, value);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Function HdrHistogram::GetClassDef (Napi::Env env) { // static
  return DefineClass (env, "HdrHistogram", {
    InstanceMethod ("add", &HdrHistogram::add),
    InstanceMethod ("close", &HdrHistogram::close),
    InstanceMethod ("countAtValue", &HdrHistogram::countAtValue),
    InstanceMethod ("getMemorySize", &HdrHistogram::getMemorySize),
    InstanceMethod ("lowestEquivalentValue", &HdrHistogram::lowestEquivalentValue),
    InstanceMethod ("max", &HdrHistogram::max),
    InstanceMethod ("mean", &HdrHistogram::mean),
    InstanceMethod ("min", &HdrHistogram::min),
    InstanceMethod ("recordCorrectedValue", &HdrHistogram::recordCorrectedValue),
    InstanceMethod ("recordCorrectedValueAtomic", &HdrHistogram::recordCorrectedValueAtomic),
    InstanceMethod ("recordCorrectedValues", &HdrHistogram::recordCorrectedValues),
    InstanceMethod ("recordCorrectedValuesAtomic", &HdrHistogram::recordCorrectedValuesAtomic),
    InstanceMethod ("record", &HdrHistogram::record),
    InstanceMethod ("recordAtomic", &HdrHistogram::recordAtomic),
    InstanceMethod ("recordValues", &HdrHistogram::recordValues),
    InstanceMethod ("recordValuesAtomic", &HdrHistogram::recordValuesAtomic),
    InstanceMethod ("reset", &HdrHistogram::reset),
    InstanceMethod ("resetInternalCounters", &HdrHistogram::resetInternalCounters),
    InstanceMethod ("stddev", &HdrHistogram::stddev),
    InstanceMethod ("percentile", &HdrHistogram::percentile),
    InstanceMethod ("valuesAreEquivalent", &HdrHistogram::valuesAreEquivalent)
  });
}

// pseudoClass HdrHistogram definition end //
// pseudoClass HdrHistogramIterator definition begin //

HdrHistogramIterator::HdrHistogramIterator (const Napi::CallbackInfo& info)
: Napi::ObjectWrap<HdrHistogramIterator> (info)
, iter ()
{
  Napi::Env env = info.Env();
}

HdrHistogramIterator::~HdrHistogramIterator () {
}

Napi::Value HdrHistogramIterator::IterNext (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  _Bool retVal = hdr_iter_next (iter);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::PercentileInit (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  int ticks_per_half_distance = getNumber<int> (info, 1);
  hdr_iter_percentile_init (iter, h, ticks_per_half_distance);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::RecordedInit (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  hdr_iter_recorded_init (iter, h);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::LinearInit (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  long long value_units_per_bucket = getNumber<long long> (info, 1);
  hdr_iter_linear_init (iter, h, value_units_per_bucket);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Function HdrHistogramIterator::GetClassDef (Napi::Env env) { // static
  return DefineClass (env, "HdrHistogramIterator", {
    InstanceMethod ("LinearInit", &HdrHistogramIterator::LinearInit),
    InstanceMethod ("IterNext", &HdrHistogramIterator::IterNext),
    InstanceMethod ("PercentileInit", &HdrHistogramIterator::PercentileInit),
    InstanceMethod ("RecordedInit", &HdrHistogramIterator::RecordedInit)
  });
}

// pseudoClass HdrHistogramIterator definition end //