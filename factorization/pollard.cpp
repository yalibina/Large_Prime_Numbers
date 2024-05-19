#include "pollard.h"

namespace Proj {

namespace detail {

large_int fx(const large_int& x, int c, const large_int& n) {
    return std::move(((x % n) * (x % n) + c) % n);
}

large_int abs_diff(const large_int& a, const large_int& b) {
    if (a > b) {
        return std::move(a - b);
    }
    return std::move(b - a);
}
} // np detail

large_int pollard_rho(const large_int& n, int max_iter, int c) {

    // f(x) = x^2 + c
    large_int x1 = 3;
    large_int x2 = detail::fx(x1, c, n);
    int range = 1;
    large_int product = 1;
    int i = 1;

    while (i <= max_iter) {
        for (int j = 0; j < range; ++j) {
            x2 = detail::fx(x2, c, n);
            product = product * detail::abs_diff(x1, x2) % n;
            i += 1;
            if (i % 10 == 0) {
                large_int g = calc_gcd(n, product);
                if (g > 1) {
                    return std::move(g);
                }
                product = 1;
            }
        }
        x1 = x2;
        range <<= 1;
        for (int j = 0; j < range; ++j) {
            x2 = detail::fx(x2, c, n);
        }
    }
    return -1;
}

large_int pollard_p1(const large_int& n, int max_iter, int c) {
    large_int m = c;
    for (int i = 1; i <= max_iter; ++i) {
        m = fast_pow_mod(m, i, n);
        if (i % 10 == 0) {
            large_int g = calc_gcd(m-1, n);
            if (g > 1) {
                return std::move(g);
            }
        }
    }
    return -1;
}

}
