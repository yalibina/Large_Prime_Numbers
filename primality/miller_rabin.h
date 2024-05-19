#ifndef LARGE_PRIME_NUMBERS_MILLER_RABIN_H
#define LARGE_PRIME_NUMBERS_MILLER_RABIN_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"
#include "../utilities/reduce.h"
#include "../utilities/fast_pow.h"
#include "trial_division_test.h"
#include "fermat.h"
#include "../utilities/rand.h"
#include "boost/multiprecision/detail/uniform_int_distribution.hpp"

namespace Proj {

namespace detail {
static constexpr int PRIMES[] = {3u,   5u,   7u,   11u,  13u,  17u,  19u,  23u,  29u,  31u,  37u,  41u,  43u,
                                 47u,  53u,  59u,  61u,  67u,  71u,  73u,  79u,  83u,  89u,  97u,  101u, 103u,
                                 107u, 109u, 113u, 127u, 131u, 137u, 139u, 149u, 151u, 157u, 163u, 167u, 173u,
                                 179u, 181u, 191u, 193u, 197u, 199u, 211u, 223u, 227u, 229u, 233u};

}

TestStatus spsp_text_base(const DecomposeProp& n_reduce, const large_int& base); // spsp = strong pseudoprime
TestStatus miller_rabin_test(const large_int& n, std::size_t trials);
TestStatus miller_rabin_test_fermat(const large_int& n, std::size_t trials);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_MILLER_RABIN_H
