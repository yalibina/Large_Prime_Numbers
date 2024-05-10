#include <iostream>
#include <cmath>

#include "utilities/large_type.h"
#include "miller_rabin.h"
#include "lucas_lehmer.h"
#include "utilities/rand.h"
#include "factorization/fermat_factor.h"
#include "factorization/trial_division.h"
#include "factorization/pollard.h"
#include "rsa.h"

int main() {
//    Proj::large_int n = "123456789012349698984577583938475";
//    assert(Proj::miller_rabin_test(n, 100000) == Proj::TestStatus::ProbablyPrime);
//
//    assert(Proj::calc_gcd(12345678901234969, 12345678901234968) == 1);
//    Proj::large_int gcd = Proj::calc_gcd(-3, 6);
//    Proj::Gcd res = Proj::knuth_gcd(-3, 6);
//    std::cout << gcd << '\n';
//    std::cout << res.n << ' ' << res.m << ' ' << res.gcd;
//    Proj::large_int n("170141183460469231731687303715884105727");
//    Proj::TestStatus res = Proj::miller_rabin_test(n, 30);
//    std::cout << magic_enum::enum_name(res);
//    Proj::large_int n = 4422;
//    Proj::large_int q = 4421;
//    std::cout << boost::multiprecision::lsb(q);
//    Proj::TestStatus res_mersenne = Proj::lucas_lehmer_test(2203);
//    std::cout << magic_enum::enum_name(res_mersenne);
//    Rand::Random rnd;
//    for (int i = 0; i < 100; ++i) {
//        Proj::large_int n = rnd.uniform(1, 1000000);
////        Proj::large_int x = Proj::int_sqrt(n);
//        int res = std::ceil(std::sqrt(static_cast<int>(n)));
//        if (x != static_cast<Proj::large_int>(res)) {
//            std::cout << n << ' ' << x << ' ' << res <<'\n';
//        }
//    }

//    Proj::large_int n = 5*7*121;
//    Proj::TrialFactors tr = Proj::trial_division_to_max(n, 11);
//    int r = tr.exp.size();
//    for (int i = 0; i < r; ++i) {
//        std::cout << tr.p[i] << ' ' << tr.exp[i] << '\n';
//    }
//    std::cout << tr.f;

//    std::cout << Proj::fermat_factorization(n);

//    std::cout << Proj::int_sqrt(5);

    Proj::large_int n(4493*4469);
    Proj::large_int res = n;
    for (int i = 1; i < 137671; ++i) {
        n += res;
    }
    Proj::large_int div = Proj::pollard_p1(n, 1000);

    std::cout << div << '\n';
    std::cout << n / div;


    return 0;
}
