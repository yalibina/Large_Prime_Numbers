#ifndef LARGE_PRIME_NUMBERS_TEST_STATUS_H
#define LARGE_PRIME_NUMBERS_TEST_STATUS_H

#include "magic_enum.hpp"

namespace Proj {
enum class TestStatus { Prime, StrongProbablyPrime, ProbablyPrime, Composite };
}

#endif  // LARGE_PRIME_NUMBERS_TEST_STATUS_H
