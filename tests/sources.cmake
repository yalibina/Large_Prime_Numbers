add_executable(
        tests
        tests/test_utils.cpp
        tests/test_prime.cpp
        tests/test_rsa.cpp
        tests/test_factors.cpp
        utilities/fast_pow.cpp utilities/gcd.cpp test_primality/miller_rabin.cpp test_primality/lucas_lehmer.cpp test_primality/fermat.cpp
        factorization/trial_division.cpp factorization/pollard.cpp factorization/fermat_factor.cpp utilities/int_sqrt.cpp utilities/reduce.cpp
        test_primality/trial_division_test.cpp utilities/prime_generator.cpp
        utilities/jacobi.cpp
        test_primality/lucas_spsp_test.cpp
        rsa/rsa.cpp
        test_primality/bpsw_test.cpp
)