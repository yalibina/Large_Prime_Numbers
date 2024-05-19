#include "fermat_factor.h"


namespace Proj {
large_int fermat_factorization(const large_int& n) {
    assert((n > 0) && (n % 2 == 1) && "N must be odd. Reduce by factor of 2 first.");
    large_int sqr = int_sqrt(n);
    large_int u = 2 * sqr + 1;
    large_int v = 1;
    large_int r = sqr * sqr - n;

    while (r != 0) {
        if (r > 0) {
            while (r > 0) {
                r -= v;
                v += 2;
            }
        } else {
            r += u;
            u += 2;
        }
    }
    large_int factor = (u+v-2) >> 1;
    return std::move(factor);

}

}