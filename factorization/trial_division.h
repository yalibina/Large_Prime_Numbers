#ifndef LARGE_PRIME_NUMBERS_TRIAL_DIVISION_H
#define LARGE_PRIME_NUMBERS_TRIAL_DIVISION_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"
#include "../utilities/int_sqrt.h"
#include "../utilities/reduce.h"
#include <vector>

namespace Proj {

struct TrialFactors {
    // n = p_1^{e_1}*p_2^{e_2}*...*p_r^{e_r}*f, p_i - primes, f - unfactored portion
    std::vector<large_int> p;
    std::vector<int> exp;
    large_int f;
};

TrialFactors trial_division_to_max(const large_int& n, const large_int& max);
}

#endif  // LARGE_PRIME_NUMBERS_TRIAL_DIVISION_H
