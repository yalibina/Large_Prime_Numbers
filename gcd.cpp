#include "gcd.h"

Proj::boost_int Proj::calc_gcd(boost_int a, boost_int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Proj::Gcd Proj::knuth_gcd(boost_int a, boost_int b) {
    std::array<boost_int, 3> u = {0, 0, a};
    std::array<boost_int, 3> v = {0, 0, a};

    boost_int q, tmp = 0;

    while (v[2] != 0) {
        q = u[2] / v[2];  // rounds toward zero

        for (int i = 0; i < 3; ++i) {
            tmp = v[i];
            v[i] = u[i] * q - v[i];
            u[i] = tmp;
        }
    }
    return {u[0], u[1], u[2]};
}
