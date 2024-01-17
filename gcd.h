#ifndef LARGE_PRIME_NUMBERS_GCD_H
#define LARGE_PRIME_NUMBERS_GCD_H

#include <boost/multiprecision/cpp_int.hpp>

namespace Proj {
using boost_int = boost::multiprecision::cpp_int;

struct Gcd {
    // gcd = m * a + n * b
    boost_int m;
    boost_int n;
    boost_int gcd;
};

boost_int calc_gcd(boost_int a, boost_int b);
Gcd knuth_gcd(boost_int a, boost_int b);  // computes gcd, m, n

// works fast with __builtin_ctz
boost_int bin_gcd(boost_int a, boost_int b);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_GCD_H
