// 2020-05-08T08:54:19.289-07:00 binding (GenerateInitFiles)
// Created by the inspiredware automated binding generator — www.inspiredware.com

#include <napi.h>
#include "binding/hdr_histogram.h"

static Napi::FunctionReference ctorHdrHistogram;
static Napi::FunctionReference ctorHdrHistogramIterator;

Napi::Object Init (Napi::Env env, Napi::Object exports) {
  Napi::Function defHdrHistogram = HdrHistogram::GetClassDef(env);
  ctorHdrHistogram = Napi::Persistent(defHdrHistogram);
  ctorHdrHistogram.SuppressDestruct();

  Napi::Function defHdrHistogramIterator = HdrHistogramIterator::GetClassDef(env);
  ctorHdrHistogramIterator = Napi::Persistent(defHdrHistogramIterator);
  ctorHdrHistogramIterator.SuppressDestruct();

  exports["HdrHistogram"] = defHdrHistogram;
  exports["HdrHistogramIterator"] = defHdrHistogramIterator;

  return exports;
}

NODE_API_MODULE(addon, Init)