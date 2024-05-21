#ifndef LARGE_PRIME_NUMBERS_PRIME_GENERATOR_H
#define LARGE_PRIME_NUMBERS_PRIME_GENERATOR_H

#include <bitset>
#include "large_type.h"
#include "rand.h"
#include "../test_primality/miller_rabin.h"

namespace Proj {
namespace detail {

constexpr int BlockSize = 64;
constexpr int Oversample = 100;
constexpr int MillerTrials = 100;
constexpr int GenerationTries = 10;
constexpr float BernoulliProb = 0.5;

void generate_full_block(std::bitset<BlockSize>& bits);
void generate_tail_block(std::bitset<BlockSize>& bits, int tail);
large_int generate_n(int bit_cnt);
large_int find_rsa_factor(const large_int& p_1);
large_int generate_rsa_large_factor(int bit_cnt);
}  // namespace detail

large_int generate_prime(int bit_cnt);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_PRIME_GENERATOR_H
