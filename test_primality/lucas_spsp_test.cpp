#include "lucas_spsp_test.h"

namespace Proj {
namespace detail {

int find_D(const large_int& n) {
    int d = 5;
    int jac = do_jacobi(d, n);

    if (jac == 0) {
        return -1; // n is composite
    }
    while (jac != -1) {
        if (d > 0) {
            d += 2;
        } else {
            d -= 2;
        }
        d = -d;
        if (abs(d) == n) {
            continue;
        }
        jac = do_jacobi(d, n);
        if (jac == 0) {
            return -1; // n is composite
        }
    }
    return d;
}

LucasSeqParameters get_init_parameters(int d) {
    LucasSeqParameters param;

    param.P = 1;
    param.Q = (1 - d) / 4;
    param.U1 = 1;
    param.V1 = param.P;

    return param;
}

std::vector<int> to_binary(large_int& n) {
    std::vector<int> bit_n;
    while (n > 0) {
        int bit = ((n & 1) == 1) ? 1 : 0;
        bit_n.push_back(bit);
        n >>= 1;
    }
    return std::move(bit_n);
}

LucasSeq get_Uk_Vk(large_int k, int p, int q) {
    large_int vl = 2;
    large_int vh = p;
    large_int ql = 1;
    large_int qh = 1;

    std::vector<int> bit_k = to_binary(k);

    for (int j = bit_k.size() - 1; j >= 0; --j) {
        ql = ql * qh;
        if (bit_k[j] == 1) {
            qh = ql * q;
            vl = vh * vl - p * ql;
            vh = vh * vh - 2 * qh;
        } else {
            qh = ql;
            vh = vh * vl - p * ql;
            vl = vl * vl - 2 * qh;
        }
    }
    LucasSeq kth;
    kth.Uk = (2 * vh - p * vl) / (p * p - 4 * q);
    kth.Vk = vl;

    return std::move(kth);
}

}  // namespace detail

TestStatus lucas_spsp_test(const large_int& n) {
    if (n == 5) {
        return TestStatus::Prime;
    }
    large_int sqr = int_sqrt(n);
    if (sqr * sqr == n) {
        return TestStatus::Composite;
    }

    int D = detail::find_D(n);
    if (D == -1) {
        return TestStatus::Composite;
    }

    detail::LucasSeqParameters params = detail::get_init_parameters(D);

    large_int delta_n = n + 1;
    DecomposeProp reduce_delta = reduce_by_2(delta_n);
    large_int d = reduce_delta.t;
    int s = reduce_delta.exp;

    detail::LucasSeq kth = detail::get_Uk_Vk(d, params.P, params.Q);
    large_int ud = kth.Uk;
    large_int vd = kth.Vk;

    if (ud % n == 0 || vd % n == 0) {
        return TestStatus::StrongProbablyPrime;
    }

    for (int r = 1; r < s; ++r) {
        vd = vd * vd - 2 * fast_pow(params.Q, d);
        if (vd % n == 0) {
            return TestStatus::StrongProbablyPrime;
        }
        d *= 2;
    }

    return TestStatus::Composite;
}

}  // namespace Proj
