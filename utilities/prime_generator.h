#ifndef LARGE_PRIME_NUMBERS_PRIME_GENERATOR_H
#define LARGE_PRIME_NUMBERS_PRIME_GENERATOR_H

#include <bitset>
#include "large_type.h"
#include "rand.h"
#include "../test_primality/miller_rabin.h"

namespace Proj {
namespace detail {

constexpr int block_size = 64;
void generate_full_block(std::bitset<block_size>& bits);
void generate_tail_block(std::bitset<block_size>& bits);
}  // namespace detail

large_int generate_prime(int bit_len);

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_PRIME_GENERATOR_H
