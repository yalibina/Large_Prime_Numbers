#include "fast_pow.h"

Proj::boost_int Proj::fast_pow(boost_int base, boost_int pow, boost_int mod) {

    boost_int res = 1;
    while (pow > 0) {
        if (pow & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        pow >>= 1;
    }

    return res;
}
