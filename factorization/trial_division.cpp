
#include "trial_division.h"

namespace Proj {

TrialFactors trial_division_to_max(const large_int& n, const large_int& max) {
    TrialFactors res;
    large_int f = n;
    int d = 0;
    // First, reduce by 2 and 3
    for (d = 2; d <= 3; ++d) {
        if (f % d == 0) {
            // n = t * k^a, k does not divide t
            DecomposeProp n_reduce = reduce_by_k(f, d);
            f = std::move(n_reduce.t);
            res.p.push_back(d);
            res.exp.push_back(n_reduce.exp);
        }
    }

    // Search for divisors of f in form of 6k+1 and 6k+5
    d = 5;
    int add = 2;
    while (d <= max && d * d <= f) {
        if (f % d == 0) {
            DecomposeProp n_reduce = reduce_by_k(f, d);
            f = std::move(n_reduce.t);
            res.p.push_back(d);
            res.exp.push_back(n_reduce.exp);
            d += add;
            add = 6 - add;
        }
    }

    // If d^2 > f, then f is prime
    if (d * d > f && f != 1) {
        res.p.push_back(f);
        res.exp.push_back(1);
        f = 1;
    }
    res.f = f;
    return std::move(res);
}

}  // namespace Proj
