#ifndef LARGE_PRIME_NUMBERS_TRIAL_DIVISION_TEST_H
#define LARGE_PRIME_NUMBERS_TRIAL_DIVISION_TEST_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"
#include "../utilities/int_sqrt.h"

namespace Proj {

TestStatus trial_division_to_max_test(const large_int& n, large_int max);

}

#endif  // LARGE_PRIME_NUMBERS_TRIAL_DIVISION_TEST_H
