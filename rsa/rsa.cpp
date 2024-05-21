#include "rsa.h"

namespace Proj {
namespace detail {

void break_number(const std::string& m_ascii, std::vector<large_int>& blocks_message) {
    int n = m_ascii.length() / BlockLen;

    std::string block;
    for (int j = 0; j < n; ++j) {
        block = "";
        for (int i = 0; i < BlockLen; ++i) {
            block += m_ascii[j * BlockLen + i];
        }
        large_int block_num(block);
        blocks_message.push_back(block_num);
    }
    block = "";
    for (int i = n * BlockLen; i < m_ascii.length(); ++i) {
        block += m_ascii[i];
    }
    large_int block_num(block);
    blocks_message.push_back(block_num);
}

std::string to_ascii(const std::string& message) {
    std::string ascii_m;
    for (char c : message) {
        ascii_m += std::to_string((toupper(c)));
    }
    return ascii_m;
}

std::string num_to_str(large_int& m) {
    std::string message;
    while (m > 0) {
        char c = (m % 100).convert_to<int8_t>();
        message = c + message;
        m /= 100;
    }
    return message;
}

}  // namespace detail

RSAPublisher::RSAPublisher(int bits_cnt) {
    generate_keys(bits_cnt);
}

int RSAPublisher::get_public_exp() const {
    return e_;
}
large_int RSAPublisher::get_public_n() {
    return n_;
}
std::string RSAPublisher::get_message() {
    return m_;
}

void RSAPublisher::decode(const std::vector<large_int>& coded_blocks) {
    std::string message;
    for (const auto& c : coded_blocks) {
        large_int m = fast_pow_mod(c, d_, n_);
        message += detail::num_to_str(m);
    }
    m_ = message;
}

void RSAPublisher::generate_keys(int bits_cnt) {
    large_int p = detail::generate_rsa_large_factor(bits_cnt);
    large_int q = detail::generate_rsa_large_factor(bits_cnt - 2);
    n_ = p * q;
    large_int phi = (p - 1) * (q - 1);

    for (int i : detail::FermatPrimes) {
        Gcd gcd = knuth_gcd(i, phi);
        if (gcd.gcd == 1) {
            e_ = i;
            while (gcd.m < 0) {
                gcd.m += phi;
            }
            d_ = gcd.m;
            break;
        }
    }
}

RSAEncoder::RSAEncoder(RSAPublisher public_key) {
    e_ = public_key.get_public_exp();
    n_ = public_key.get_public_n();
}
int RSAEncoder::get_exp() const {
    return e_;
}
large_int RSAEncoder::get_n() {
    return n_;
}

std::vector<large_int> RSAEncoder::encode(const std::string& message) {
    std::string ascii_m = detail::to_ascii(message);
    std::vector<large_int> blocks_message;
    detail::break_number(ascii_m, blocks_message);
    for (auto& block : blocks_message) {
        block = fast_pow_mod(block, get_exp(), get_n());
    }
    return blocks_message;
}

}  // namespace Proj
