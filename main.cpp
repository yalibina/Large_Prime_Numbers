#include <iostream>

#include "gcd.h"
#include "large_type.h"
#include "miller_rabin.h"

int main() {
    Proj::large_int n = 12345678901234969;
    assert(Proj::miller_rabin_test(n, 100000) == Proj::TestStatus::ProbablyPrime);

    assert(Proj::calc_gcd(12345678901234969, 12345678901234968) == 1);

    return 0;
}
