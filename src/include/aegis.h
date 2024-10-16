#ifndef aegis_H
#define aegis_H

#include <stdint.h>

#if !defined(__clang__) && !defined(__GNUC__)
#    ifdef __attribute__
#        undef __attribute__
#    endif
#    define __attribute__(a)
#endif

#ifndef CRYPTO_ALIGN
#    if defined(__INTEL_COMPILER) || defined(_MSC_VER)
#        define CRYPTO_ALIGN(x) __declspec(align(x))
#    else
#        define CRYPTO_ALIGN(x) __attribute__((aligned(x)))
#    endif
#endif

#include "aegis128l.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Compare two 16-byte blocks for equality.
 *
 * This function is designed to be used in constant-time code.
 *
 * Returns 0 if the blocks are equal, -1 otherwise.
 */
int aegis_verify_16(const uint8_t *x, const uint8_t *y) __attribute__((warn_unused_result));

/* Compare two 32-byte blocks for equality.
 *
 * This function is designed to be used in constant-time code.
 *
 * Returns 0 if the blocks are equal, -1 otherwise.
 */
int aegis_verify_32(const uint8_t *x, const uint8_t *y) __attribute__((warn_unused_result));

#ifdef __cplusplus
}
#endif

#endif
