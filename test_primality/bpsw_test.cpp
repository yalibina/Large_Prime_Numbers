#include "bpsw_test.h"

namespace Proj {
TestStatus bpsw_test(const large_int& n) {
    assert(n > 0 && "N must be > 0.");
    if (n == 2 || n == 3) {
        return TestStatus::Prime;
    }
    if (n % 2 == 0) {
        return TestStatus::Composite;
    }
    if (test_trial_division_to_max(n, detail::TrialDivMax) == TestStatus::Composite) {
        return TestStatus::Composite;
    }
    if (test_spsp_base(n, 2) == TestStatus::Composite) {
        return TestStatus::Composite;
    }
    if (test_lucas_spsp(n) == TestStatus::Composite) {
        return TestStatus::Composite;
    }
    return TestStatus::StrongProbablyPrime;
}
}  // namespace Proj
