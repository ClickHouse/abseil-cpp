#ifndef ABSL_BASE_INTERNAL_FILC_H_
#define ABSL_BASE_INTERNAL_FILC_H_

#include <cstdint>

#if defined(__FILC__)
#include <stdfil.h>
#endif

inline void* absl_filc_zmkptr(void* object, uintptr_t address) {
#if defined(__FILC__)
  return zmkptr(object, address);
#else
  (void)object;
  return reinterpret_cast<void*>(address);
#endif
}

inline void* absl_filc_zorptr(void* pointer, uintptr_t bits) {
#if defined(__FILC__)
  return zorptr(pointer, bits);
#else
  return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(pointer) | bits);
#endif
}

inline void* absl_filc_zandptr(void* pointer, uintptr_t bits) {
#if defined(__FILC__)
  return zandptr(pointer, bits);
#else
  return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(pointer) & bits);
#endif
}

inline void* absl_filc_zxorptr(void* pointer, uintptr_t bits) {
#if defined(__FILC__)
  return zxorptr(pointer, bits);
#else
  return reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(pointer) ^ bits);
#endif
}

#endif  // ABSL_BASE_INTERNAL_FILC_H_
