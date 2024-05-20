#include <gtest/gtest.h>

#include "../rsa/rsa.h"
#include "rsa_messages.h"

TEST(RSA, Equal) {
    for (int i = 60; i < 500; i += 50) {
        Proj::RSAPublisher alice(i);
        Proj::RSAEncoder bob(alice);
        for (auto message : TestRSA::messages) {
            std::vector<Proj::large_int> c = bob.encode(message);
            alice.decode(c);
            std::string m = alice.get_message();
            EXPECT_EQ(message, m);
        }
    }
}
