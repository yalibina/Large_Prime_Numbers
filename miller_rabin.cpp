#include "miller_rabin.h"

#include "fast_pow.h"

#include <boost/multiprecision/detail/uniform_int_distribution.hpp>
#include <random>

namespace Proj {

// n - 1 = t * 2^a, t odd
DecomposeProp reduce(const large_int& n) {
    large_int t = n - 1;
    int a = 0;
    while (t % 2 == 0) {
        t >>= 1;
        a += 1;
    }
    return {n, t, a};
}

TestStatus test_n_base(DecomposeProp n_reduce, const large_int& base) {
    large_int t = n_reduce.t;
    large_int n = n_reduce.n;
    large_int test = fast_pow(base, t, n);
    if (test == 1 || test == (n_reduce.n - 1)) {
        return TestStatus::ProbablyPrime;
    }

    for (int j = 0; j < n_reduce.exp_two; ++j) {
        test = (test * test) % n_reduce.n;
        if (test == (n_reduce.n - 1)) {
            return TestStatus::ProbablyPrime;
        }
    }
    return TestStatus::Composite;
}

TestStatus miller_rabin_test(const large_int& n, std::size_t trials) {
    std::mt19937 gen;
    boost::multiprecision::uniform_int_distribution<large_int> dist(2, n - 2);

    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    DecomposeProp n_reduce = reduce(n);

    for (int i = 0; i < trials; ++i) {
        large_int base = dist(gen);
        if (test_n_base(n_reduce, base) == TestStatus::Composite) {
            return TestStatus::Composite;
        }
    }

    return TestStatus::ProbablyPrime;
}
}  // namespace Proj
