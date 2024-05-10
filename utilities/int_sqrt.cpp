#include "int_sqrt.h"

namespace Proj {

large_int int_sqrt(const large_int& n) {
    large_int l = 1;
    large_int r = n;
    while (l < r) {
        large_int m = l + ((r - l) >> 1);
        if (m * m == n) {
            return m;
        } else if (m * m < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return std::move(l);
}

}