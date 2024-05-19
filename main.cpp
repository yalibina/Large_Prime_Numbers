#include <iostream>
#include <cmath>

#include "utilities/large_type.h"
#include "test_primality/miller_rabin.h"
#include "test_primality/lucas_lehmer.h"
#include "utilities/rand.h"
#include "factorization/fermat_factor.h"
#include "factorization/trial_division.h"
#include "factorization/pollard.h"
#include "rsa.h"

#include "utilities/prime_generator.h"
#include "utilities/jacobi.h"
#include "test_primality/lucas_spsp_test.h"

int main() {

    Proj::large_int n("170141183460469231731687303715884105727");
    std::cout << magic_enum::enum_name(Proj::miller_rabin_test(n, 30)) << '\n';

    for (int i = 0; i < 10; ++i) {
        Proj::large_int n = Proj::generate_prime(20);
        std::cout << magic_enum::enum_name(Proj::lucas_spsp_test(n)) << '\n';
    }


    return 0;
}
