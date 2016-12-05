#ifndef ADDEM_H
#define ADDEM_H
#include <stdint.h>

/**
 *   Computes and returns sum of A[0]:A[Sz-1].
 *   Pre:
 *         A points to an array of dimension at least Sz
 *         A[0:Sz-1] are initialized
 *   Returns:
 *         sum of A[0] through A[Sz-1]
 */
int32_t AddEm(const int32_t* const A, uint32_t Sz);

#endif

