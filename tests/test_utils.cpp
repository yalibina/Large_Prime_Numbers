#include <gtest/gtest.h>
#include "../utilities/fast_pow.h"
#include "../utilities/gcd.h"
#include "../utilities/int_sqrt.h"
#include "../utilities/prime_generator.h"

TEST(Utilities, Sqrt) {
    static Rand::Random rnd;
    for (int i = 0; i < 1000; ++i) {
        Proj::large_int max("1029383547584594356528304694678923");
        Proj::large_int n = rnd.uniform(2, max);
        Proj::large_int sqrt = Proj::int_sqrt(n);
        EXPECT_LT((sqrt - 1) * (sqrt - 1), n);
        EXPECT_GE(sqrt * sqrt, n);
    }
}

TEST(Utilities, Gcd_compare_small) {
    static Rand::Random rnd;

    for (int i = 0; i < 1000; ++i) {
        Proj::large_int max_small = 1000000;
        Proj::large_int a = rnd.uniform(2, max_small);
        Proj::large_int b = rnd.uniform(2, max_small);
        Proj::large_int gcd1 = Proj::calc_gcd(a, b);
        Proj::large_int gcd2 = Proj::knuth_gcd(a, b).gcd;
        ASSERT_EQ(gcd1, gcd2);
    }
}
TEST(Utilities, Gcd_compare_large) {
    static Rand::Random rnd;

    for (int i = 0; i < 1000; ++i) {
        Proj::large_int max_large("102938354758459435652830469467892353");
        Proj::large_int a = rnd.uniform(2, max_large);
        Proj::large_int b = rnd.uniform(2, max_large);
        Proj::large_int gcd1 = Proj::calc_gcd(a, b);
        Proj::large_int gcd2 = Proj::knuth_gcd(a, b).gcd;
        ASSERT_EQ(gcd1, gcd2);
    }
}

TEST(Utilities, Extended_gcd_coef) {
    static Rand::Random rnd;

    for (int i = 0; i < 1000; ++i) {
        Proj::large_int max_large("102938354758459435652830469467892353");
        Proj::large_int a = rnd.uniform(2, max_large);
        Proj::large_int b = rnd.uniform(2, max_large);
        Proj::Gcd gcd = Proj::knuth_gcd(a, b);
        ASSERT_EQ(gcd.gcd, a * gcd.m + b * gcd.n);
    }
}

TEST(Utilities, Prime_gen) {
    static Rand::Random rnd;
    for (int i = 0; i < 1000; ++i) {
        Proj::large_int n = Proj::generate_prime(10);
        EXPECT_EQ(Proj::test_trial_division_to_max(n), Proj::TestStatus::Prime);
    }
}
