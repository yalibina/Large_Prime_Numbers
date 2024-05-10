#ifndef LARGE_PRIME_NUMBERS_GCD_H
#define LARGE_PRIME_NUMBERS_GCD_H

#include "large_type.h"

namespace Proj {

struct Gcd {
    // gcd(a,b) = m * a + n * b
    large_int m;
    large_int n;
    large_int gcd;
};

large_int calc_gcd(large_int a, large_int b);
Gcd knuth_gcd(const large_int& a, const large_int& b);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_GCD_H
