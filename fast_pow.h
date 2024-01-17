#ifndef LARGE_PRIME_NUMBERS_FAST_POW_H
#define LARGE_PRIME_NUMBERS_FAST_POW_H

#include <boost/multiprecision/cpp_int.hpp>

namespace Proj {
using boost_int = boost::multiprecision::cpp_int;

// maybe use built in powm?
boost_int fast_pow(boost_int base, boost_int pow, boost_int mod);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_FAST_POW_H
