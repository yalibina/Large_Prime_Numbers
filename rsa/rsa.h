#ifndef LARGE_PRIME_NUMBERS_RSA_H
#define LARGE_PRIME_NUMBERS_RSA_H

#include "../utilities/large_type.h"
#include "../utilities/fast_pow.h"
#include "../utilities/prime_generator.h"
#include "../utilities/gcd.h"
#include "../test_primality/miller_rabin.h"

namespace Proj {
namespace detail {

constexpr int FermatPrimes[] = {17, 257, 65537};
constexpr int BlockLen = 16;

void break_number(const std::string& m_ascii, std::vector<large_int>& blocks_message);
std::string to_ascii(const std::string& message);
std::string num_to_str(large_int& m);
}  // namespace detail

class RSAPublisher {
public:
    explicit RSAPublisher(int bits_cnt);

    int get_public_exp() const;
    large_int get_public_n();
    std::string get_message();
    void decode(const std::vector<large_int>& coded_blocks);

private:
    void generate_keys(int bits_cnt);

    int e_;
    large_int n_;
    large_int d_;
    std::string m_;
};

class RSAEncoder {
public:
    explicit RSAEncoder(RSAPublisher public_key);

    int get_exp() const;
    large_int get_n();

    std::vector<large_int> encode(const std::string& message);

private:
    int e_;
    large_int n_;
    std::string m_;
};

}  // namespace Proj

#endif  // LARGE_PRIME_NUMBERS_RSA_H
