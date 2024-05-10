#ifndef LARGE_PRIME_NUMBERS_MILLER_RABIN_H
#define LARGE_PRIME_NUMBERS_MILLER_RABIN_H

#include "utilities/large_type.h"
#include "utilities/test_status.h"
#include "utilities/reduce.h"
#include <boost/multiprecision/detail/uniform_int_distribution.hpp>

namespace Proj {

TestStatus spsp_text_base(const DecomposeProp& n_reduce, const large_int& base); // spsp = strong pseudoprime
TestStatus miller_rabin_test(const large_int& n, std::size_t trials);
TestStatus miller_rabin_test_fermat(const large_int& n, std::size_t trials);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_MILLER_RABIN_H
