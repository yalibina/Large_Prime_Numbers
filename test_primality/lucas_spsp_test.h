#ifndef LARGE_PRIME_NUMBERS_LUCAS_SPSP_TEST_H
#define LARGE_PRIME_NUMBERS_LUCAS_SPSP_TEST_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"
#include "../utilities/reduce.h"
#include "../utilities/jacobi.h"
#include "../utilities/int_sqrt.h"
#include "../utilities/fast_pow.h"

namespace Proj {
namespace detail {

constexpr int InitD = 5;  // for sequence 5 -7 11 -13 15 -17 ...

struct LucasSeqParameters {
    int U1;
    int V1;
    int P;
    int Q;
};

struct LucasSeq {
    large_int Uk;
    large_int Vk;
};

int find_D(const large_int& n);
std::vector<int> to_binary(large_int& n);
LucasSeqParameters get_init_parameters(int D);
LucasSeq get_Uk_Vk(large_int k, int p, int q);

}  // namespace detail

TestStatus test_lucas_spsp(const large_int& n);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_LUCAS_SPSP_TEST_H
