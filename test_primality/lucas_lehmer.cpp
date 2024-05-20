#include "lucas_lehmer.h"

namespace Proj {

// Detects whether M(n) = 2^n - 1 is prime
TestStatus test_lucas_lehmer(int n) {
    assert(n % 2 == 1 && "n must be odd.");
    large_int m = fast_pow(2, n) - 1;
    large_int s = 4;
    for (size_t i = 2; i < n; ++i) {
        s = (s * s - 2) % m;
    }
    if (s == 0) {
        return TestStatus::Prime;
    }
    return TestStatus::Composite;
}

}  // namespace Proj
