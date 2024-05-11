#include <string>
#include "atcoder/convolution"

std::vector<bool> wildcard_pattern_matching(const std::string& s, const std::string& t, char wild = '?') {
    int n = s.size(), m = t.size();
    assert(n >= m and n > 0);
    char mini = s[0];
    for (const auto& c : s) {
        if (c != wild) {
            mini = std::min(mini, c);
        }
    }
    for (const auto& c : s) {
        if (c != wild) {
            mini = std::min(mini, c);
        }
    }
    std::vector<atcoder::modint998244353> f1(n), f2(n), f3(n), g1(m), g2(m), g3(m);
    for (int i = 0; i < n; i++) {
        f1[i] = (s[i] == wild ? 0 : s[i] - mini + 1);
        f2[i] = f1[i] * f1[i];
        f3[i] = f2[i] * f1[i];
    }
    for (int i = 0; i < m; i++) {
        g1[m - 1 - i] = (t[i] == wild ? 0 : t[i] - mini + 1);
        g2[m - 1 - i] = g1[m - 1 - i] * g1[m - 1 - i];
        g3[m - 1 - i] = g2[m - 1 - i] * g1[m - 1 - i];
    }
    auto h1 = atcoder::convolution(f1, g3);
    auto h2 = atcoder::convolution(f2, g2);
    auto h3 = atcoder::convolution(f3, g1);
    std::vector<bool> res(n - m + 1);
    for (int i = 0; i < n - m + 1; i++) {
        res[i] = (h1[m - 1 + i] - 2 * h2[m - 1 + i] + h3[m - 1 + i] == 0);
    }
    return res;
}