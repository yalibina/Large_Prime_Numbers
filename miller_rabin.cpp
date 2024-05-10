#include "miller_rabin.h"

#include "utilities/fast_pow.h"
#include "trial_division_test.h"
#include "fermat.h"
#include "utilities/rand.h"

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

static constexpr int PRIMES[] =
    {
        3u, 5u, 7u, 11u, 13u, 17u, 19u, 23u, 29u, 31u,
        37u, 41u, 43u, 47u, 53u, 59u, 61u, 67u, 71u, 73u,
        79u, 83u, 89u, 97u, 101u, 103u, 107u, 109u, 113u,
        127u, 131u, 137u, 139u, 149u, 151u, 157u, 163u,
        167u, 173u, 179u, 181u, 191u, 193u, 197u, 199u,
        211u, 223u, 227u, 229u, 233u};

TestStatus miller_rabin_test_fermat(const large_int& n, std::size_t trials) {
    static Rand::Random rnd;

    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    if (n <= 227) {
        for (int prime : PRIMES) {
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

//    if (n <= 227) {
//        for (int prime : PRIMES) {
//            if (n == prime) {
//                return TestStatus::Prime;
//            }
//        }
//    }

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
