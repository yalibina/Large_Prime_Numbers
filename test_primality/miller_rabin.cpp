#include "miller_rabin.h"

namespace Proj {

TestStatus test_spsp_base(const large_int& n, const large_int& base) {
    large_int nm1 = n - 1;
    DecomposeProp nm1_reduce = reduce_by_2(nm1);

    large_int test = fast_pow_mod(base, nm1_reduce.t, n);
    if (test == 1 || test == (n - 1)) {
        return TestStatus::StrongProbablyPrime;
    }

    for (int j = 1; j < nm1_reduce.exp; ++j) {
        test = (test * test) % n;
        if (test == (n - 1)) {
            return TestStatus::StrongProbablyPrime;
        }
    }
    return TestStatus::Composite;
}

TestStatus test_miller_rabin_fermat(const large_int& n, std::size_t trials) {
    static Rand::Random rnd;

    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    if (n <= 227) {
        for (int prime : detail::Primes) {
            if (n == prime) {
                return TestStatus::Prime;
            }
        }
    }

    // Check small factors
    if (test_trial_division_to_max(n, detail::TrialDivMax) == TestStatus::Composite) {
        return TestStatus::Composite;
    }

    // Fermat test
    if (test_fermat_base(n, 228) == TestStatus::Composite) {  // We've excluded all factors below 228
        return TestStatus::Composite;
    }

    // Strong pseudoprime test
    for (int i = 0; i < trials; ++i) {
        large_int base = rnd.uniform(2, n - 2);
        if (test_spsp_base(n, base) == TestStatus::Composite) {
            return TestStatus::Composite;
        }
    }

    return TestStatus::StrongProbablyPrime;
}

TestStatus test_miller_rabin(const large_int& n, std::size_t trials) {
    static Rand::Random rnd;

    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    // Check small factors
    if (test_trial_division_to_max(n, detail::TrialDivMax) == TestStatus::Composite) {
        return TestStatus::Composite;
    }

    // Strong pseudoprime test

    for (int i = 0; i < trials; ++i) {
        large_int base = rnd.uniform(2, n - 2);
        if (test_spsp_base(n, base) == TestStatus::Composite) {
            return TestStatus::Composite;
        }
    }

    return TestStatus::StrongProbablyPrime;
}
}  // namespace Proj
