#include "prime_generator.h"

namespace Proj {

namespace detail {

void generate_full_block(std::bitset<block_size>& bits) {
    static Rand::Random rnd;
    for (int i = 0; i < block_size; ++i) {
        int rand_bit = rnd.bernoulli(0.5);
        bits[i] = rand_bit;
    }
}

void generate_tail_block(std::bitset<block_size>& bits, int tail) {
    static Rand::Random rnd;
    for (int i = 0; i < tail; ++i) {
        int rand_bit = rnd.bernoulli(0.5);
        bits[i] = rand_bit;
    }
    bits[tail - 1] = 1;
}

large_int generate_n(int bit_len) {
    large_int n = 0;

    int tail = bit_len % detail::block_size;
    int has_tail = (tail == 0) ? 0 : 1;

    int block_n = bit_len / detail::block_size + has_tail;

    std::bitset<detail::block_size> bits;

    for (int j = 0; j < (block_n - has_tail); ++j) {
        detail::generate_full_block(bits);
        if (j == 0) { // odd number
            bits[0] = 1;
        }
        if (j == block_n - 1) {
            bits[detail::block_size - 1] = 1; // exact number of bits
        }
        unsigned long long block = bits.to_ullong();
        large_int block_li(block); // so that shifting doesn't overflow
        n += (block_li <<= (j * detail::block_size));
    }

    if (has_tail) {
        bits.reset();
        detail::generate_tail_block(bits, tail);
        unsigned long long block = bits.to_ullong();
        large_int block_li(block); // so that shifting doesn't overflow
        n += (block_li <<= ((block_n - 1) * detail::block_size));
    }
    return n;
}

}  // namespace detail

large_int generate_prime(int bit_len) {
    assert((bit_len > 0) && "Number length must be > 0.");

    int max_trials = bit_len + 100;

    int tries = 0;
    while(tries < 10) {
        large_int n = detail::generate_n(bit_len);

        for (int i = 0; i < max_trials; ++i) {
            if (miller_rabin_test(n, 100) == TestStatus::Prime || miller_rabin_test(n, 100) == TestStatus::StrongProbablyPrime) {
                return n;
            }
            n += 2;
        }

        ++tries;
    }

    return -1;
}

}  // namespace Proj
