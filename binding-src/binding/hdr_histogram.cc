// 2020-05-14T16:54:27.408-07:00 binding hdr_histogram.c (GenerateDefinitions)
// Created by the inspiredware automated binding generator — www.inspiredware.com

#include "hdr_histogram.h"
#include "napi-ingress.h"
#include "hdr_histogram_log.h"

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
  if (status) {
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

Napi::Value HdrHistogram::getEncoded (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  char * encoded = NULL;
  int result = hdr_log_encode(histogram, &encoded);
  if (!encoded || result != 0) {
    Napi::Error::New(env, "failed to encode").ThrowAsJavaScriptException();
  }
  Napi::Value jsRetVal = Napi::Buffer<char>::Copy(env, encoded, strlen(encoded));
  delete encoded; // TODO: verify this call is required
  return jsRetVal;
}

Napi::Value HdrHistogram::setEncoded (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Buffer<char> buffer = info[0].As< Napi::Buffer<char> >();
  char * encoded = buffer.Data();
  size_t len = buffer.Length();
  hdr_log_decode(&histogram, encoded, len); // TODO: verify any existing histogram is freed
  return env.Undefined();
}

Napi::Function HdrHistogram::GetClassDef (Napi::Env env) { // static
  return DefineClass (env, "HdrHistogram", {
    InstanceMethod ("add", &HdrHistogram::add),
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
    InstanceMethod ("valuesAreEquivalent", &HdrHistogram::valuesAreEquivalent),
    InstanceMethod ("getEncoded", &HdrHistogram::getEncoded),
    InstanceMethod ("setEncoded", &HdrHistogram::setEncoded),
  });
}

// pseudoClass HdrHistogram definition end //
// pseudoClass HdrHistogramIterator definition begin //

HdrHistogramIterator::HdrHistogramIterator (const Napi::CallbackInfo& info)
: Napi::ObjectWrap<HdrHistogramIterator> (info)
, iterStruct ()
, iter (&iterStruct)
, histogram (Napi::ObjectWrap<HdrHistogram>::Unwrap(info[0].As<Napi::Object>())->histogram)
{
  Napi::Env env = info.Env();
  hdr_iter_init (iter, histogram);
}

HdrHistogramIterator::~HdrHistogramIterator () {
}

Napi::Value HdrHistogramIterator::next (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  _Bool retVal = hdr_iter_next (iter);
  Napi::Value jsRetVal = Boolean::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::initPercentile (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  int ticks_per_half_distance = getNumber<int> (info, 0);
  hdr_iter_percentile_init (iter, histogram, ticks_per_half_distance);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::initRecorded (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  hdr_iter_recorded_init (iter, histogram);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::initLinear (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value_units_per_bucket = getNumber<long long> (info, 0);
  hdr_iter_linear_init (iter, histogram, value_units_per_bucket);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::initLog (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  long long value_units_first_bucket = getNumber<long long> (info, 0);
  double log_base = getNumber<double> (info, 1);
  hdr_iter_log_init (iter, histogram, value_units_first_bucket, log_base);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::getValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Value getVal = Number::New(env, iter->value);
  return getVal;
}

Napi::Value HdrHistogramIterator::getPercentile (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Value getVal = Number::New(env, iter->specifics.percentiles.percentile);
  return getVal;
}

Napi::Function HdrHistogramIterator::GetClassDef (Napi::Env env) { // static
  return DefineClass (env, "HdrHistogramIterator", {
    InstanceMethod ("initLinear", &HdrHistogramIterator::initLinear),
    InstanceMethod ("initLog", &HdrHistogramIterator::initLog),
    InstanceMethod ("initPercentile", &HdrHistogramIterator::initPercentile),
    InstanceMethod ("initRecorded", &HdrHistogramIterator::initRecorded),
    InstanceMethod ("next", &HdrHistogramIterator::next),
    InstanceMethod ("getValue", &HdrHistogramIterator::getValue),
    InstanceMethod ("getPercentile", &HdrHistogramIterator::getPercentile),
  });
}

// pseudoClass HdrHistogramIterator definition end //