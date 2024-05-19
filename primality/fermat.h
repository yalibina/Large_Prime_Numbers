#ifndef LARGE_PRIME_NUMBERS_FERMAT_H
#define LARGE_PRIME_NUMBERS_FERMAT_H

#include "../utilities/large_type.h"
#include "../utilities/test_status.h"

namespace Proj {

TestStatus fermat_base_test(const large_int& n, size_t base);

} // namespace Proj

#endif //LARGE_PRIME_NUMBERS_FERMAT_H
