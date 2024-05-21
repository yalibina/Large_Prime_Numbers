#ifndef LARGE_PRIME_NUMBERS_RAND_H
#define LARGE_PRIME_NUMBERS_RAND_H

#include "large_type.h"
#include "boost/multiprecision/detail/uniform_int_distribution.hpp"
#include <random>

namespace Rand {
class Random {
public:
    Proj::large_int uniform(const Proj::large_int& a, const Proj::large_int& b) {
        boost::multiprecision::uniform_int_distribution<Proj::large_int> dist(a, b);
        return dist(gen_);
    }

    int bernoulli(float p) {
        std::bernoulli_distribution dist(p);
        return (dist(gen_) ? 1 : 0);
    };

private:
    std::mt19937 gen_;
};
}  // namespace Rand

#endif  // LARGE_PRIME_NUMBERS_RAND_H
