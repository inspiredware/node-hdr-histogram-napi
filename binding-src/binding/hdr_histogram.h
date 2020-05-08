// 2020-05-08T08:54:18.306-07:00 binding hdr_histogram.c (GenerateDeclarations)
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
  Napi::Value ResetInternalCounters (const Napi::CallbackInfo& info);
  Napi::Value Close (const Napi::CallbackInfo& info);
  Napi::Value Reset (const Napi::CallbackInfo& info);
  Napi::Value GetMemorySize (const Napi::CallbackInfo& info);
  Napi::Value RecordValue (const Napi::CallbackInfo& info);
  Napi::Value RecordValueAtomic (const Napi::CallbackInfo& info);
  Napi::Value RecordValues (const Napi::CallbackInfo& info);
  Napi::Value RecordValuesAtomic (const Napi::CallbackInfo& info);
  Napi::Value RecordCorrectedValue (const Napi::CallbackInfo& info);
  Napi::Value RecordCorrectedValueAtomic (const Napi::CallbackInfo& info);
  Napi::Value RecordCorrectedValues (const Napi::CallbackInfo& info);
  Napi::Value RecordCorrectedValuesAtomic (const Napi::CallbackInfo& info);
  Napi::Value Add (const Napi::CallbackInfo& info);
  Napi::Value Max (const Napi::CallbackInfo& info);
  Napi::Value Min (const Napi::CallbackInfo& info);
  Napi::Value ValueAtPercentile (const Napi::CallbackInfo& info);
  Napi::Value Mean (const Napi::CallbackInfo& info);
  Napi::Value StdDev (const Napi::CallbackInfo& info);
  Napi::Value ValuesAreEquivalent (const Napi::CallbackInfo& info);
  Napi::Value LowestEquivalentValue (const Napi::CallbackInfo& info);
  Napi::Value CountAtValue (const Napi::CallbackInfo& info);

public:
  hdr_histogram* histogram;
};
// pseudoClass HdrHistogram declaration end //
// pseudoClass HdrHistogramIterator declaration begin //
class HdrHistogramIterator : public Napi::ObjectWrap<HdrHistogramIterator> {
 public:
  HdrHistogramIterator (const Napi::CallbackInfo& info);
  ~HdrHistogramIterator ();
  static Napi::Function GetClassDef (Napi::Env env);

 private:
  Napi::Value IterNext (const Napi::CallbackInfo& info);
  Napi::Value PercentileInit (const Napi::CallbackInfo& info);
  Napi::Value RecordedInit (const Napi::CallbackInfo& info);
  Napi::Value LinearInit (const Napi::CallbackInfo& info);

  hdr_iter* iter;
};
// pseudoClass HdrHistogramIterator declaration end //