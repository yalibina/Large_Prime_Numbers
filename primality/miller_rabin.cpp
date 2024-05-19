#include "miller_rabin.h"

#include "../utilities/fast_pow.h"
#include "trial_division_test.h"
#include "fermat.h"
#include "../utilities/rand.h"

namespace Proj {

TestStatus spsp_test_base(const DecomposeProp& n_reduce, const large_int& base) {
    large_int n = n_reduce.n + 1;

    large_int test = fast_pow_mod(base, n_reduce.t, n);
    if (test == 1 || test == (n - 1)) {
        return TestStatus::StrongProbablyPrime;
    }

    for (int j = 1; j < n_reduce.exp; ++j) {
        test = (test * test) % n;
        if (test == (n - 1)) {
            return TestStatus::StrongProbablyPrime;
        }
    }
    return TestStatus::Composite;
}


TestStatus miller_rabin_test_fermat(const large_int& n, std::size_t trials) {
    static Rand::Random rnd;

    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    if (n <= 227) {
        for (int prime : detail::PRIMES) {
            if (n == prime) {
                return TestStatus::Prime;
            }
        }
    }

    // Check small factors
    if (trial_division_to_max_test(n, 5000) == TestStatus::Composite) {
        return TestStatus::Composite;
    }

    // Fermat test
    if (fermat_base_test(n, 228) == TestStatus::Composite) { // We've excluded all factors below 228
        return TestStatus::Composite;
    }

    // Strong pseudoprime test
    DecomposeProp n_reduce = reduce_by_2(n);

    for (int i = 0; i < trials; ++i) {
        large_int base = rnd.uniform(2, n-2);
        if (spsp_test_base(n_reduce, base) == TestStatus::Composite) {
            return TestStatus::Composite;
        }
    }

    return TestStatus::StrongProbablyPrime;
}

TestStatus miller_rabin_test(const large_int& n, std::size_t trials) {
    static Rand::Random rnd;

    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    // Check small factors
    if (trial_division_to_max_test(n, 5000) == TestStatus::Composite) {
        return TestStatus::Composite;
    }

    // Strong pseudoprime test
    DecomposeProp n_reduce = reduce_by_2(n - 1);

    for (int i = 0; i < trials; ++i) {
        large_int base = rnd.uniform(2, n-2);
        if (spsp_test_base(n_reduce, base) == TestStatus::Composite) {
            return TestStatus::Composite;
        }
    }

    return TestStatus::StrongProbablyPrime;
}
}  // namespace Proj
