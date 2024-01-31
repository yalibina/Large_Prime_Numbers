#include "gcd.h"

namespace Proj {

large_int calc_gcd(large_int a, large_int b) {
    large_int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Gcd knuth_gcd(large_int a, large_int b) {
    std::array<large_int, 3> u = {0, 0, a};
    std::array<large_int, 3> v = {0, 0, a};

    large_int q, tmp = 0;

    while (v[2] != 0) {
        q = u[2] / v[2];

        for (int i = 0; i < 3; ++i) {
            tmp = v[i];
            v[i] = u[i] * q - v[i];
            u[i] = tmp;
        }
    }
    return {u[0], u[1], u[2]};
}
}  // namespace Proj
