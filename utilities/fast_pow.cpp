#include "fast_pow.h"

namespace Proj {

large_int fast_pow(const large_int &base, large_int pow) {
    assert(pow >= 0 && "Power must be non-negative.");

    large_int res = 1;
    large_int y = base;

    while (pow > 0) {
        if (pow & 1) {
            res = res * y;
        }

        y = y * y;
        pow >>= 1;
    }

    return res;
}

large_int fast_pow_mod(const large_int &base, large_int pow, const large_int &mod) {
    assert(pow >= 0 && "Power must be non-negative.");
    assert(mod > 0 && "Modulus must be positive.");

    large_int res = 1;
    large_int y = base;

    while (pow > 0) {
        if (pow & 1) {
            res = large_int((res * y) % mod);
        }

        y = large_int((y * y) % mod);
        pow >>= 1;
    }

    return res;
}
}  // namespace Proj
