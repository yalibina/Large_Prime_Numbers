#include "gcd.h"

namespace Proj {

large_int calc_gcd(large_int a, large_int b) {
    assert(a >= 0 && "Value 'a' must be >= 0.");
    assert(b > 0 && "Value 'b' must be > 0.");
    large_int tmp;
    while (b != 0) {
        tmp = std::move(b);
        b = a % b;
        a = tmp;
    }
    return a;
}

Gcd knuth_gcd(const large_int& a, const large_int& b) {
    assert(a >= 0 && "Value 'a' must be >= 0.");
    assert(b > 0 && "Value 'b' must be > 0.");

    std::array<large_int, 3> u = {1, 0, a};
    std::array<large_int, 3> v = {0, 1, b};
    large_int q = 0;

    while (v[2] != 0) {
        q = u[2] / v[2];
        large_int tmp;
        for (int i = 0; i < 3; ++i) {
            tmp = std::move(v[i]);
            v[i] = u[i] - q * tmp;
            u[i] = std::move(tmp);
        }
    }
    return {std::move(u[0]), std::move(u[1]), std::move(u[2])};
}
}  // namespace Proj
