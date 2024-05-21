#include <gtest/gtest.h>
#include "../utilities/prime_generator.h"
#include "../factorization/fermat_factor.h"
#include "../factorization/pollard.h"
#include "../factorization/trial_division.h"

#include "small_primes.h"
#include <random>

TEST(Factor, FermatSmall) {
    int ind1 = rand() % 3000;
    int ind2 = rand() % 3000;
    Proj::large_int f1 = TestPrimes::SmallPrimes[ind1];
    Proj::large_int f2 = TestPrimes::SmallPrimes[ind2];
    Proj::large_int n = f1 * f2;
    Proj::large_int f = Proj::fermat_factorization(n);
    EXPECT_EQ(n % f, 0);
}

TEST(Factor, FermatPrime) {
    int ind1 = rand() % 3000;
    Proj::large_int n = TestPrimes::SmallPrimes[ind1];
    Proj::large_int f = Proj::fermat_factorization(n);
    EXPECT_EQ(f, n);
}

TEST(Factor, PollardRhoSmall) {
    int ind1 = rand() % 3000;
    int ind2 = rand() % 3000;
    Proj::large_int f1 = TestPrimes::SmallPrimes[ind1];
    Proj::large_int f2 = TestPrimes::SmallPrimes[ind2];
    Proj::large_int n = f1 * f2;
    Proj::large_int f = Proj::pollard_rho(n, 1000);
    EXPECT_EQ(n % f, 0);
}

TEST(Factor, PollardRhoBigger) {
    int ind1 = rand() % 3000;
    int ind2 = rand() % 3000;
    int ind3 = rand() % 3000;
    Proj::large_int f1 = TestPrimes::SmallPrimes[ind1];
    Proj::large_int f2 = TestPrimes::SmallPrimes[ind2];
    Proj::large_int f3 = TestPrimes::SmallPrimes[ind3];

    Proj::large_int n = f1 * f2 * f3;
    Proj::large_int f = Proj::pollard_rho(n, 1000);

    EXPECT_EQ(n % f, 0);
}

TEST(Factor, PollardP1Small) {
    int ind1 = rand() % 3000;
    int ind2 = rand() % 3000;
    Proj::large_int f1 = TestPrimes::SmallPrimes[ind1];
    Proj::large_int f2 = TestPrimes::SmallPrimes[ind2];
    Proj::large_int n = f1 * f2;
    Proj::large_int f = Proj::pollard_p1(n, 1000);
    EXPECT_EQ(n % f, 0);
}

TEST(Factor, PollardP1Bigger) {
    int ind1 = rand() % 3000;
    int ind2 = rand() % 3000;
    int ind3 = rand() % 3000;
    Proj::large_int f1 = TestPrimes::SmallPrimes[ind1];
    Proj::large_int f2 = TestPrimes::SmallPrimes[ind2];
    Proj::large_int f3 = TestPrimes::SmallPrimes[ind3];

    Proj::large_int n = f1 * f2 * f3;
    Proj::large_int f = Proj::pollard_p1(n, 1000);
    EXPECT_EQ(n % f, 0);
}
