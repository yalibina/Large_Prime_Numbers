#ifndef LARGE_PRIME_NUMBERS_POLLARD_H
#define LARGE_PRIME_NUMBERS_POLLARD_H

#include "../utilities/large_type.h"
#include "../utilities/gcd.h"
#include "../utilities/fast_pow.h"


namespace Proj {

// Only run these algorithms if n is proved composite!

// Using polynomial f(x) = x^2 + c
large_int pollard_rho(const large_int& n, int max_iter, int c = 1);
large_int pollard_p1(const large_int& n, int max_iter, int c = 2);

}

#endif  // LARGE_PRIME_NUMBERS_POLLARD_H
