// 2020-07-08T13:10:42.804-07:00 binding (GenerateInitFiles)
// © Copyright 2020 Simply Inspired Software, Inc., dba inspiredware
// Released under the MIT License — https://en.wikipedia.org/wiki/MIT_License
// Created by the inspiredware automated binding generator — https://inspiredware.com

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