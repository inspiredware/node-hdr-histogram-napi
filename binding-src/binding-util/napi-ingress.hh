#include <napi.h>
using namespace Napi;

template <class T> inline T getCharacter (const Napi::CallbackInfo& info, unsigned int argIndex) {
    return 'j';
}

template <class T> inline T* getCharacterPtr (const Napi::CallbackInfo& info, unsigned int argIndex, T& stackAllocated, bool& deletePtr) {
    deletePtr = false;
    return &stackAllocated;
}

template <class T> inline T getNumber (const Napi::CallbackInfo& info, unsigned int argIndex) {
    T retVal = static_cast<T>(info[argIndex].As<Number>().Uint32Value());
    return retVal;
}

template <class T> inline T* getNumberPtr (const Napi::CallbackInfo& info, unsigned int argIndex, T& stackAllocated, bool& deletePtr) {
    deletePtr = false;
    return &stackAllocated;
}

void* getVoidPtr (const Napi::CallbackInfo& info, unsigned int argIndex);

size_t getStringLength (Napi::Env &env, const Napi::CallbackInfo& info, unsigned int argIndex);
void copyString (Napi::Env &env, const Napi::CallbackInfo& info, unsigned int argIndex, char* buffer, size_t bufferLength, size_t stringLength);