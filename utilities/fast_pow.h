#ifndef LARGE_PRIME_NUMBERS_FAST_POW_H
#define LARGE_PRIME_NUMBERS_FAST_POW_H

#include "large_type.h"

namespace Proj {

large_int fast_pow(const large_int &base, large_int pow);
large_int fast_pow_mod(const large_int &base, large_int pow, const large_int &mod);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_FAST_POW_H
