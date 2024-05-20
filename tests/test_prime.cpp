#include <gtest/gtest.h>
#include "mersenne_exp.h"
#include "small_primes.h"

#include "../test_primality/lucas_lehmer.h"
#include "../test_primality/miller_rabin.h"
#include "../test_primality/lucas_spsp_test.h"
#include "../test_primality/trial_division_test.h"
#include "../test_primality/fermat.h"
#include "../utilities/fast_pow.h"

TEST(Primality, TrialDiv) {
    for (auto prime : TestPrimes::SmallPrimes) {
        EXPECT_EQ(Proj::test_trial_division_to_max(prime), Proj::TestStatus::Prime);
    }
}

TEST(Primality, LucasLehmer) {
    for (auto exp : TestPrimes::Mersenne_exp) {
        EXPECT_EQ(Proj::test_lucas_lehmer(exp), Proj::TestStatus::Prime);
    }
}

TEST(Primality, MillerRabin) {
    for (auto prime : TestPrimes::SmallPrimes) {
        EXPECT_NE(Proj::test_miller_rabin(prime, 100), Proj::TestStatus::Composite);
    }
    for (auto exp : TestPrimes::Mersenne_exp) {
        Proj::large_int n = Proj::fast_pow(2, exp) - 1;
        EXPECT_NE(Proj::test_miller_rabin(n, 100), Proj::TestStatus::Composite);
    }
}

TEST(Primality, FermatSmall) {
    for (auto prime : TestPrimes::SmallPrimes) {
        EXPECT_EQ(Proj::test_fermat_base(prime, 2), Proj::TestStatus::ProbablyPrime);
        EXPECT_EQ(Proj::test_fermat_base(prime, 3), Proj::TestStatus::ProbablyPrime);
        EXPECT_EQ(Proj::test_fermat_base(prime, 5), Proj::TestStatus::ProbablyPrime);
    }
}

TEST(Primality, FermatMersenne) {
    for (auto exp : TestPrimes::Mersenne_exp) {
        Proj::large_int n = Proj::fast_pow(2, exp) - 1;
        if (n > 5) {
            EXPECT_EQ(Proj::test_fermat_base(n, 2), Proj::TestStatus::ProbablyPrime);
            EXPECT_EQ(Proj::test_fermat_base(n, 3), Proj::TestStatus::ProbablyPrime);
            EXPECT_EQ(Proj::test_fermat_base(n, 5), Proj::TestStatus::ProbablyPrime);
        }
    }
}

TEST(Primality, LucasSmall) {
    for (auto prime : TestPrimes::SmallPrimes) {
        EXPECT_NE(Proj::test_lucas_spsp(prime), Proj::TestStatus::Composite);
    }
}
