#include <iostream>

#include "test_primality/miller_rabin.h"
#include "rsa/rsa.h"

int main() {

    Proj::large_int n("170141183460469231731687303715884105727");
    std::cout << magic_enum::enum_name(Proj::test_miller_rabin(n, 30)) << '\n';

    Proj::RSAPublisher alice(200);
    Proj::RSAEncoder bob(alice);
    std::string message = "don't tell anyone!";
    std::vector<Proj::large_int> c = bob.encode(message);
    alice.decode(c);
    std::cout << alice.get_message();

    return 0;
}
