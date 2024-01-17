#include "miller_rabin.h"

#include "fast_pow.h"

// n is odd > 3, (b,n) = 1
// returns 0 if n is composite, 1 if n is strong pseudoprime for the base b
bool Proj::miller_rabin(boost_int n, int b, int k) {
    // n - 1 = t * 2^a, t odd
    boost_int t = n - 1;
    int a = 0;
    while (t % 2 == 0) {
        t >>= 1;
        a += 1;
    }
    boost_int test = Proj::fast_pow(boost_int(b), t, n);
    if (test == 1 or test == n - 1) {
        return true;
    }
    for (int i = 1; i < a; ++i) {
        test = (test * test) % n;
        if (test == n - 1) {
            return true;
        }
    }

    return false;
}