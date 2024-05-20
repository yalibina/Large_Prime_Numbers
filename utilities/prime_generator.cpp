#include "prime_generator.h"

namespace Proj {

namespace detail {

void generate_full_block(std::bitset<BlockSize>& bits) {
    static Rand::Random rnd;
    for (int i = 0; i < BlockSize; ++i) {
        int rand_bit = rnd.bernoulli(BernoulliProb);
        bits[i] = rand_bit;
    }
}

void generate_tail_block(std::bitset<BlockSize>& bits, int tail) {
    static Rand::Random rnd;
    for (int i = 0; i < tail; ++i) {
        int rand_bit = rnd.bernoulli(BernoulliProb);
        bits[i] = rand_bit;
    }
    bits[tail - 1] = 1;
}

large_int generate_n(int bit_cnt) {
    large_int n = 0;

    int tail = bit_cnt % detail::BlockSize;
    int has_tail = (tail == 0) ? 0 : 1;

    int block_n = bit_cnt / detail::BlockSize + has_tail;

    std::bitset<detail::BlockSize> bits;

    for (int j = 0; j < (block_n - has_tail); ++j) {
        detail::generate_full_block(bits);
        if (j == 0) {
            bits[0] = 1;  // odd number
        }
        if (j == block_n - 1) {
            bits[detail::BlockSize - 1] = 1;  // exact number of bits
        }
        uint64_t block = bits.to_ullong();
        large_int block_li(block);  // so that shifting doesn't overflow
        n += (block_li <<= (j * detail::BlockSize));
    }

    if (has_tail) {
        bits.reset();
        detail::generate_tail_block(bits, tail);
        uint64_t block = bits.to_ullong();
        large_int block_li(block);  // so that shifting doesn't overflow
        n += (block_li <<= ((block_n - 1) * detail::BlockSize));
    }
    return n;
}

large_int find_rsa_factor(const large_int& p_1) {
    bool p_prime = false;
    large_int p = 0;
    int i = 1;
    while (!p_prime) {
        p = 2 * i * p_1 + 1;
        if (test_miller_rabin(p, detail::MillerTrials) == TestStatus::StrongProbablyPrime ||
            test_miller_rabin(p, detail::MillerTrials) == TestStatus::Prime) {
            p_prime = true;
        }

        i += 2;
    }
    return p;
}

large_int generate_rsa_large_factor(int bit_cnt) {
    assert((bit_cnt > 0) && "Number of bits must be > 0.");

    large_int p_2 = generate_prime(bit_cnt - 5);
    large_int p_1 = find_rsa_factor(p_2);
    large_int p = find_rsa_factor(p_1);

    return p;
}

}  // namespace detail

large_int generate_prime(int bit_cnt) {
    assert((bit_cnt > 0) && "Number of bits must be > 0.");

    int max_trials = bit_cnt + detail::Oversample;

    int tries = 0;
    while (tries < detail::GenerationTries) {
        large_int n = detail::generate_n(bit_cnt);

        for (int i = 0; i < max_trials; ++i) {
            if (test_miller_rabin(n, detail::MillerTrials) == TestStatus::Prime ||
                test_miller_rabin(n, detail::MillerTrials) == TestStatus::StrongProbablyPrime) {
                return n;
            }
            n += 2;
        }

        ++tries;
    }

    return -1;
}

}  // namespace Proj
