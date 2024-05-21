#pragma once
#include "../atcoder/convolution"

template <typename T> T BostanMori(std::vector<T> Q, std::vector<T> P, long long N) {
    assert(Q[0] == 1);
    assert(P.size() < Q.size());
    const int d = Q.size();
    for (; N; N >>= 1) {
        auto Q_neg = Q;
        for (int i = 1; i < int(Q.size()); i += 2) Q_neg[i] *= -1;
        P = atcoder::convolution(P, Q_neg);
        Q = atcoder::convolution(Q, Q_neg);
        for (int i = N & 1; i < int(P.size()); i += 2) P[i >> 1] = P[i];
        for (int i = 0; i < int(Q.size()); i += 2) Q[i >> 1] = Q[i];
        P.resize(d - 1);
        Q.resize(d);
    }
    return P[0];
}

/**
 * @brief compute Nth term of linearly recurrent sequence a_n = \sum_{i = 1}^d c_i a_{n - i}
 *
 * @tparam T F_p
 * @param a first d elements of the sequence a_0, a_1, ... , a_{d - 1}
 * @param c coefficients of the linear recurrence c_1, c_2, ... , c_d
 * @param N the number of term you want to calculate
 * @return T Nth term of linearly recurrent sequence
 */
template <typename T> T LinearRecurrence(std::vector<T> a, std::vector<T> c, long long N) {
    assert(a.size() >= c.size());
    const int d = c.size();
    std::vector<T> Q(d + 1);
    Q[0] = 1;
    for (int i = 0; i < d; i++) Q[i + 1] = -c[i];
    std::vector<T> P = atcoder::convolution(a, Q);
    P.resize(d);
    return BostanMori(Q, P, N);
}
