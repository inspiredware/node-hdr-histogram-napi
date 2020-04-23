#include "napi-ingress.h"
#include <napi.h>
#include <climits>

void* getVoidPtr (const Napi::CallbackInfo& info, unsigned int argIndex) {
    return 0;
}

size_t getStringLength (Napi::Env &env, const Napi::CallbackInfo& info, unsigned int argIndex) {
    size_t stringLength = 0;
    napi_status status = napi_get_value_string_utf8 (env, info[argIndex], NULL, 0, &stringLength);
    if (status != napi_ok) throw "Unable to determine string length.";
    return stringLength;
}

void copyString (Napi::Env &env, const Napi::CallbackInfo& info, unsigned int argIndex, char* buffer, size_t bufferLength, size_t stringLength) {
    size_t copiedLength = 0;
    napi_status status = napi_get_value_string_utf8 (env, info[argIndex], buffer, bufferLength, &copiedLength);
    if (status != napi_ok) throw "String copy failed.";
    if (copiedLength != stringLength) throw "String copy length mismatch.";
}
