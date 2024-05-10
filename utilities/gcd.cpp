#include "gcd.h"

namespace Proj {

large_int calc_gcd(large_int a, large_int b) {
    assert(a >= 0 && "Value 'a' must be >= 0.");
    assert(b > 0 && "Value 'b' must be > 0.");
    while (b != 0) {
        a = std::exchange(b, a % b);
    }
    return a;
}

Gcd knuth_gcd(const large_int& a, const large_int& b) {
    assert(a >= 0 && "Value 'a' must be >= 0.");
    assert(b > 0 && "Value 'b' must be > 0.");
    std::array<large_int, 3> u = {0, 1, a};
    std::array<large_int, 3> v = {1, 0, b};

    large_int q = 0;

    while (v[2] != 0) {
        q = u[2] / v[2];

        for (int i = 0; i < 3; ++i) {
            u[i] = std::exchange(v[i], u[i] - q * v[i]);
        }
    }
    return {std::move(u[0]), std::move(u[1]), std::move(u[2])};
}
}  // namespace Proj
