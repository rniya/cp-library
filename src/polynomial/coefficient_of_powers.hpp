#include "FormalPowerSeries.hpp"

namespace internal {

template <typename T>
std::vector<FormalPowerSeries<T>> convolution2d(const std::vector<FormalPowerSeries<T>>& f,
                                                const std::vector<FormalPowerSeries<T>>& g) {
    int h1 = f.size(), w1 = h1 == 0 ? 0 : f[0].size();
    int h2 = g.size(), w2 = h2 == 0 ? 0 : g[0].size();
    int h = h1 + h2 - 1, w = w1 + w2 - 1;
    std::vector<T> ff(h1 * w, 0), gg(h2 * w, 0);
    for (int x = 0; x < h1; x++) {
        assert(f[x].size() == w1);
        for (int y = 0; y < w1; y++) {
            ff[x * w + y] = f[x][y];
        }
    }
    for (int x = 0; x < h2; x++) {
        assert(g[x].size() == w2);
        for (int y = 0; y < w2; y++) {
            gg[x * w + y] = g[x][y];
        }
    }
    auto hh = atcoder::convolution(ff, gg);
    std::vector res(h, FormalPowerSeries<T>(w));
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++) {
            res[x][y] = hh[x * w + y];
        }
    }
    return res;
}

}  // namespace internal

template <typename T> std::vector<T> coefficient_of_powers(std::vector<T> f, std::vector<T> g, int n, int deg) {
    assert(f[0] == 0);
    f.resize(deg + 1);
    g.resize(deg + 1);
    std::vector P(deg + 1, FormalPowerSeries<T>(2, T(0))), Q(deg + 1, FormalPowerSeries<T>(2, T(0)));
    for (int i = 0; i <= deg; i++) {
        P[i][0] = g[i];
        Q[i][1] = -f[i];
    }
    Q[0][0] = 1;
    for (; deg; deg >>= 1) {
        auto Q_neg = Q;
        for (int i = 1; i < int(Q_neg.size()); i += 2) {
            for (auto& val : Q_neg[i]) {
                val = -val;
            }
        }
        auto nP = internal::convolution2d(P, Q_neg);
        auto nQ = internal::convolution2d(Q, Q_neg);
        P.resize(deg / 2 + 1);
        Q.resize(deg / 2 + 1);
        for (int i = 0; i <= deg / 2; i++) P[i] = nP[i << 1 | (deg & 1)];
        for (int i = 0; i <= deg / 2; i++) Q[i] = nQ[i << 1];
        for (int i = 0; i < int(P.size()); i++) {
            if (int(P[i].size()) > n)
                P[i].resize(n);
            else
                break;
        }
        for (int i = 0; i < int(Q.size()); i++) {
            if (int(Q[i].size()) > n)
                Q[i].resize(n);
            else
                break;
        }
    }
    P[0].resize(n);
    Q[0].resize(n);
    return P[0] * Q[0].inv();
}