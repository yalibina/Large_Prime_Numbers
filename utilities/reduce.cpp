#include "reduce.h"

namespace Proj {

DecomposeProp reduce_by_2(const large_int& n) {
    large_int t = n;
    int a = 0;
    while (t % 2 == 0) {
        t >>= 1;
        ++a;
    }
    return {std::move(t), a};
}

DecomposeProp reduce_by_k(const large_int& n, const large_int& k) {
    large_int t = n;
    int a = 0;
    while (t % k == 0) {
        t /= k;
        ++a;
    }
    return {std::move(t), a};
}

}  // namespace Proj
