
#include "trial_division_test.h"

namespace Proj {

TestStatus test_trial_division_to_max(const large_int &n, large_int max) {
    if (n == 2) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }

    if (max == -1 || max > n) {
        max = int_sqrt(n);
    }

    for (int i = 3; i <= max; i += 2) {
        if (n % i == 0) {
            return TestStatus::Composite;
        }
    }
    return TestStatus::Prime;
}

}  // namespace Proj
