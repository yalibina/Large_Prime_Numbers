#ifndef LARGE_PRIME_NUMBERS_BPSW_TEST_H
#define LARGE_PRIME_NUMBERS_BPSW_TEST_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"
#include "../test_primality/trial_division_test.h"
#include "../test_primality/miller_rabin.h"
#include "../test_primality/lucas_spsp_test.h"
namespace Proj {
TestStatus bpsw_test(const large_int& n);
}
#endif  // LARGE_PRIME_NUMBERS_BPSW_TEST_H
