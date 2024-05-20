#include "fermat.h"

namespace Proj {

TestStatus test_fermat_base(const large_int &n, size_t base) {
    assert((n % 2 == 1) && "n must be odd.");
    assert((calc_gcd(n, base) == 1) && "n and base must be coprime.");
    large_int res = fast_pow_mod(base, n - 1, n);
    if (res == 1) {
        return TestStatus::ProbablyPrime;
    }
    return TestStatus::Composite;
}
}  // namespace Proj
