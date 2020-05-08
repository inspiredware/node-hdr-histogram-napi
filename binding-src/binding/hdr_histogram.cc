// 2020-05-08T08:54:18.835-07:00 binding hdr_histogram.c (GenerateDefinitions)
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
  long long min = getNumber<long long> (info, 0);
  long long max = getNumber<long long> (info, 1);
  int sigFigures = getNumber<int> (info, 2);
  int result = hdr_init (min, max, sigFigures, &histogram);
  if (result) {} // TODO: implement error handling
}

HdrHistogram::~HdrHistogram () {
  hdr_close (histogram); // frees memory
}

Napi::Value HdrHistogram::ResetInternalCounters (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  hdr_reset_internal_counters (h);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::Close (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  hdr_close (h);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::Reset (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  hdr_reset (h);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::GetMemorySize (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  unsigned long retVal = hdr_get_memory_size (h);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  _Bool retVal = hdr_record_value (h, value);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordValueAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  _Bool retVal = hdr_record_value_atomic (h, value);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordValues (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long count = getNumber<long long> (info, 2);
  _Bool retVal = hdr_record_values (h, value, count);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordValuesAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long count = getNumber<long long> (info, 2);
  _Bool retVal = hdr_record_values_atomic (h, value, count);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordCorrectedValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long expected_interval = getNumber<long long> (info, 2);
  _Bool retVal = hdr_record_corrected_value (h, value, expected_interval);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordCorrectedValueAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long expected_interval = getNumber<long long> (info, 2);
  _Bool retVal = hdr_record_corrected_value_atomic (h, value, expected_interval);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordCorrectedValues (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long count = getNumber<long long> (info, 2);
  long long expected_interval = getNumber<long long> (info, 3);
  _Bool retVal = hdr_record_corrected_values (h, value, count, expected_interval);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::RecordCorrectedValuesAtomic (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long count = getNumber<long long> (info, 2);
  long long expected_interval = getNumber<long long> (info, 3);
  _Bool retVal = hdr_record_corrected_values_atomic (h, value, count, expected_interval);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::Add (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_histogram * h = 0;
  const struct hdr_histogram * from = 0;
  long long retVal = hdr_add (h, from);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::Max (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  long long retVal = hdr_max (h);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::Min (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  long long retVal = hdr_min (h);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::ValueAtPercentile (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  float percentile;
  long long retVal = hdr_value_at_percentile (h, percentile);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::Mean (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  double retVal = hdr_mean (h);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::StdDev (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  double retVal = hdr_stddev (h);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::ValuesAreEquivalent (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  long long a = getNumber<long long> (info, 1);
  long long b = getNumber<long long> (info, 2);
  _Bool retVal = hdr_values_are_equivalent (h, a, b);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogram::LowestEquivalentValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long retVal = hdr_lowest_equivalent_value (h, value);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Value HdrHistogram::CountAtValue (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  const struct hdr_histogram * h = 0;
  long long value = getNumber<long long> (info, 1);
  long long retVal = hdr_count_at_value (h, value);
  Napi::Value jsRetVal = Number::New(env, retVal);
  return jsRetVal;
}

Napi::Function HdrHistogram::GetClassDef (Napi::Env env) { // static
  return DefineClass (env, "HdrHistogram", {
    InstanceMethod ("Add", &HdrHistogram::Add),
    InstanceMethod ("Close", &HdrHistogram::Close),
    InstanceMethod ("CountAtValue", &HdrHistogram::CountAtValue),
    InstanceMethod ("GetMemorySize", &HdrHistogram::GetMemorySize),
    InstanceMethod ("LowestEquivalentValue", &HdrHistogram::LowestEquivalentValue),
    InstanceMethod ("Max", &HdrHistogram::Max),
    InstanceMethod ("Mean", &HdrHistogram::Mean),
    InstanceMethod ("Min", &HdrHistogram::Min),
    InstanceMethod ("RecordCorrectedValue", &HdrHistogram::RecordCorrectedValue),
    InstanceMethod ("RecordCorrectedValueAtomic", &HdrHistogram::RecordCorrectedValueAtomic),
    InstanceMethod ("RecordCorrectedValues", &HdrHistogram::RecordCorrectedValues),
    InstanceMethod ("RecordCorrectedValuesAtomic", &HdrHistogram::RecordCorrectedValuesAtomic),
    InstanceMethod ("RecordValue", &HdrHistogram::RecordValue),
    InstanceMethod ("RecordValueAtomic", &HdrHistogram::RecordValueAtomic),
    InstanceMethod ("RecordValues", &HdrHistogram::RecordValues),
    InstanceMethod ("RecordValuesAtomic", &HdrHistogram::RecordValuesAtomic),
    InstanceMethod ("Reset", &HdrHistogram::Reset),
    InstanceMethod ("ResetInternalCounters", &HdrHistogram::ResetInternalCounters),
    InstanceMethod ("StdDev", &HdrHistogram::StdDev),
    InstanceMethod ("ValueAtPercentile", &HdrHistogram::ValueAtPercentile),
    InstanceMethod ("ValuesAreEquivalent", &HdrHistogram::ValuesAreEquivalent)
  });
}

// pseudoClass HdrHistogram definition end //
// pseudoClass HdrHistogramIterator definition begin //

HdrHistogramIterator::HdrHistogramIterator (const Napi::CallbackInfo& info)
: Napi::ObjectWrap<HdrHistogramIterator> (info)
, iter ()
{
}

HdrHistogramIterator::~HdrHistogramIterator () {
}

Napi::Value HdrHistogramIterator::IterNext (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_iter * iter = 0;
  _Bool retVal = hdr_iter_next (iter);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::PercentileInit (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_iter * iter = 0;
  const struct hdr_histogram * h = 0;
  int ticks_per_half_distance = getNumber<int> (info, 2);
  hdr_iter_percentile_init (iter, h, ticks_per_half_distance);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::RecordedInit (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_iter * iter = 0;
  const struct hdr_histogram * h = 0;
  hdr_iter_recorded_init (iter, h);
  Napi::Value jsRetVal = env.Undefined();
  return jsRetVal;
}

Napi::Value HdrHistogramIterator::LinearInit (const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  struct hdr_iter * iter = 0;
  const struct hdr_histogram * h = 0;
  long long value_units_per_bucket = getNumber<long long> (info, 2);
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