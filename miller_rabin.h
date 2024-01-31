#ifndef LARGE_PRIME_NUMBERS_MILLER_RABIN_H
#define LARGE_PRIME_NUMBERS_MILLER_RABIN_H

#include "large_type.h"

namespace Proj {

enum class TestStatus { Prime, Composite, ProbablyPrime };

struct DecomposeProp {
    large_int n;
    large_int t;
    int exp_two;
};

DecomposeProp reduce(const large_int& n);
TestStatus test_n_base(DecomposeProp n_reduce, const large_int& base);

TestStatus miller_rabin_test(const large_int& n, std::size_t trials);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_MILLER_RABIN_H
