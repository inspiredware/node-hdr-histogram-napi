// 2020-06-16T17:09:22.946-07:00 binding hdr_histogram.c (GenerateDeclarations)
// © Copyright 2020 Simply Inspired Software, Inc., dba inspiredware
// Created by the inspiredware automated binding generator — www.inspiredware.com

#include <napi.h>
#include <hdr_histogram.h> // from the origin library

// pseudoClass HdrHistogram declaration begin //

class HdrHistogram : public Napi::ObjectWrap<HdrHistogram> {
 public:
  HdrHistogram (const Napi::CallbackInfo& info);
  ~HdrHistogram ();
  static Napi::Function GetClassDef (Napi::Env env);

 private:
  Napi::Value recordCorrectedValue (const Napi::CallbackInfo& info);
  Napi::Value recordCorrectedValueAtomic (const Napi::CallbackInfo& info);
  Napi::Value recordCorrectedValues (const Napi::CallbackInfo& info);
  Napi::Value recordCorrectedValuesAtomic (const Napi::CallbackInfo& info);
  Napi::Value record (const Napi::CallbackInfo& info);
  Napi::Value recordAtomic (const Napi::CallbackInfo& info);
  Napi::Value recordValues (const Napi::CallbackInfo& info);
  Napi::Value recordValuesAtomic (const Napi::CallbackInfo& info);
  Napi::Value valuesAreEquivalent (const Napi::CallbackInfo& info);
  Napi::Value mean (const Napi::CallbackInfo& info);
  Napi::Value stddev (const Napi::CallbackInfo& info);
  Napi::Value add (const Napi::CallbackInfo& info);
  Napi::Value addWhileCorrectingForCoordinatedOmission (const Napi::CallbackInfo& info);
  Napi::Value countAtValue (const Napi::CallbackInfo& info);
  Napi::Value lowestEquivalentValue (const Napi::CallbackInfo& info);
  Napi::Value max (const Napi::CallbackInfo& info);
  Napi::Value medianEquivalentValue (const Napi::CallbackInfo& info);
  Napi::Value min (const Napi::CallbackInfo& info);
  Napi::Value nextNonEquivalentValue (const Napi::CallbackInfo& info);
  Napi::Value sizeOfEquivalentValueRange (const Napi::CallbackInfo& info);
  Napi::Value percentile (const Napi::CallbackInfo& info);
  Napi::Value getMemorySize (const Napi::CallbackInfo& info);
  Napi::Value reset (const Napi::CallbackInfo& info);
  Napi::Value resetInternalCounters (const Napi::CallbackInfo& info);

  Napi::Value getEncoded (const Napi::CallbackInfo& info);
  Napi::Value getHighestTrackableValue (const Napi::CallbackInfo& info);
  Napi::Value getLowestTrackableValue (const Napi::CallbackInfo& info);
  Napi::Value getSignificantFigures (const Napi::CallbackInfo& info);
  Napi::Value getTotalCount (const Napi::CallbackInfo& info);
  Napi::Value getUnitMagnitude (const Napi::CallbackInfo& info);
  Napi::Value setEncoded (const Napi::CallbackInfo& info);

public:
  struct hdr_histogram * histogram;
};
// pseudoClass HdrHistogram declaration end //
// pseudoClass HdrHistogramIterator declaration begin //

class HdrHistogramIterator : public Napi::ObjectWrap<HdrHistogramIterator> {
 public:
  HdrHistogramIterator (const Napi::CallbackInfo& info);
  ~HdrHistogramIterator ();
  static Napi::Function GetClassDef (Napi::Env env);

 private:
  Napi::Value next (const Napi::CallbackInfo& info);
  Napi::Value initLinear (const Napi::CallbackInfo& info);
  Napi::Value initLog (const Napi::CallbackInfo& info);
  Napi::Value initPercentile (const Napi::CallbackInfo& info);
  Napi::Value initRecorded (const Napi::CallbackInfo& info);

  Napi::Value getValue (const Napi::CallbackInfo& info);
  Napi::Value getPercentile (const Napi::CallbackInfo& info);

  struct hdr_iter iterStruct;
  struct hdr_iter * iter;
  struct hdr_histogram * histogram;
};
// pseudoClass HdrHistogramIterator declaration end //