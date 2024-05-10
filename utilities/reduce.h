#ifndef LARGE_PRIME_NUMBERS_REDUCE_H
#define LARGE_PRIME_NUMBERS_REDUCE_H

#include "large_type.h"

namespace Proj {

// n = t * k^a, k does not divide t
struct DecomposeProp {
    large_int n;
    large_int t;
    int exp;
};


DecomposeProp reduce_by_2(const large_int& n); // k = 2
DecomposeProp reduce_by_k(const large_int& n, const large_int& k);

}

#endif  // LARGE_PRIME_NUMBERS_REDUCE_H
