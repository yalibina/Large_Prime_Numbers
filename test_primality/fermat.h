#ifndef LARGE_PRIME_NUMBERS_FERMAT_H
#define LARGE_PRIME_NUMBERS_FERMAT_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"
#include "../utilities/fast_pow.h"
#include "../utilities/gcd.h"
#include <assert.h>

namespace Proj {

TestStatus test_fermat_base(const large_int &n, size_t base);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_FERMAT_H
