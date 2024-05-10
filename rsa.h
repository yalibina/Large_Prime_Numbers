#ifndef LARGE_PRIME_NUMBERS_RSA_H
#define LARGE_PRIME_NUMBERS_RSA_H


#include "utilities/large_type.h"
#include "utilities/fast_pow.h"

namespace Proj {

class RSA {
public:

    RSA(int bits_cnt);

    size_t e;
    large_int n;
    void decode(size_t c);

private:
    size_t m_;
    size_t d_;
    void generate_keys(int bits_cnt);
};

size_t rsa_encode(size_t e, large_int n, std::string m);

}

#endif //LARGE_PRIME_NUMBERS_RSA_H
