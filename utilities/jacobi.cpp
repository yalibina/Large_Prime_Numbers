#include "jacobi.h"

namespace Proj {
namespace detail {

int do_jacobi(large_int d, large_int n) {
    assert(n % 2 == 1 && "Denominator must be odd.");
    assert(d != 0 && "Numerator must be non-zero.");

    if (calc_gcd(abs(d), n) != 1) {
        return 0;
    }

    int jacobi = 1;
    d %= n;

    // make d > 0
    if (d < 0) {
        d = -d;
        if (n % 4 == 3) {
            jacobi = -jacobi;
        }
    }

    while (d != 0) {

        // reduce by 2
        int t = 0;
        while (d % 2 == 0) {
            d /= 2;
            ++t;
        }
        if (t % 2 == 1) {
            if (n % 8 == 3 || n % 8 == 5) {
                jacobi = -jacobi;
            }
        }

        // law of quadratic reciprocity
        if (d % 4 == 3 && n % 4 == 3) {
            jacobi = -jacobi;
        }
        n = std::exchange(d, n % d);
    }
    return jacobi;
}
}  // namespace detail
}  // namespace Proj
