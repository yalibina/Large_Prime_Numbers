#ifndef LARGE_PRIME_NUMBERS_JACOBI_H
#define LARGE_PRIME_NUMBERS_JACOBI_H

#include "large_type.h"
#include "assert.h"
#include "gcd.h"

namespace Proj {
namespace detail {

int do_jacobi(large_int d, large_int n);

}  // namespace detail
}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_JACOBI_H
