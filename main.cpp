#include <iostream>
#include <cmath>

#include "utilities/large_type.h"
#include "primality/miller_rabin.h"
#include "primality/lucas_lehmer.h"
#include "utilities/rand.h"
#include "factorization/fermat_factor.h"
#include "factorization/trial_division.h"
#include "factorization/pollard.h"
#include "rsa.h"

#include "utilities/prime_generator.h"

int main() {

    Proj::large_int n = Proj::generate_prime(200);
    std::cout << n;

    return 0;
}
