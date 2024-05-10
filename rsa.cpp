
#include "rsa.h"

namespace Proj{
void RSA::generate_keys(int bits_cnt) {
    e = 1;
    n = 3;
    d_ = 78;
}

size_t encode() {
    return 5;
}

void RSA::decode(size_t c) {
    m_ = d_ + 1;
}
RSA::RSA(int bits_cnt) {
    generate_keys(bits_cnt);
}
}