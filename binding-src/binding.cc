// 2020-06-16T17:09:23.639-07:00 binding (GenerateInitFiles)
// © Copyright 2020 Simply Inspired Software, Inc., dba inspiredware
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