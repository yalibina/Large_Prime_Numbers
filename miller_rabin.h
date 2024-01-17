#ifndef LARGE_PRIME_NUMBERS_MILLER_RABIN_H
#define LARGE_PRIME_NUMBERS_MILLER_RABIN_H

#include <boost/multiprecision/cpp_int.hpp>

namespace Proj {
using boost_int = boost::multiprecision::cpp_int;

bool miller_rabin(boost_int n, int b, int k = 1);
// k is number of iterations with different bases. gotta figure it out, for now it is unused

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_MILLER_RABIN_H
