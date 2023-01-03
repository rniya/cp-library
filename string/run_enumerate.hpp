#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace run_enumerate {

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

template <class T> std::vector<std::tuple<int, int, int>> enumerate(const std::vector<T>& s) {
    int n = s.size();
    std::vector<std::tuple<int, int, int>> res;
    auto dfs = [&](auto&& self, int l, int r) -> void {
        if (r - l <= 1) return;
        int m = (l + r) >> 1;
        self(self, l, m);
        self(self, m, r);
        std::vector<T> sl(s.rbegin() + n - m, s.rbegin() + n - l);
        sl.insert(sl.end(), s.rbegin() + n - r, s.rbegin() + n - l);
        std::vector<T> sr(s.begin() + m, s.begin() + r);
        sr.insert(sr.end(), s.begin() + l, s.begin() + r);
        auto zsl = z_algorithm(sl), zsr = z_algorithm(sr);
        for (int t = 1; t <= m - l; t++) {
            int ml = std::max(l, m - t - zsl[t]), mr = std::min(r, m + zsr[r - l - t]);
            if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))
                res.emplace_back(ml, mr, t);
        }
        for (int t = 1; t <= r - m; t++) {
            int ml = std::max(l, m - zsl[r - l - t]), mr = std::min(r, m + t + zsr[t]);
            if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))
                res.emplace_back(ml, mr, t);
        }
    };
    dfs(dfs, 0, n);
    std::sort(res.begin(), res.end());
    std::vector<std::tuple<int, int, int>> nres;
    int pl = -1, pr = -1;
    for (auto [l, r, t] : res) {
        if (l == pl and r == pr) continue;
        pl = l, pr = r;
        nres.emplace_back(t, l, r);
    }
    return nres;
}

std::vector<std::tuple<int, int, int>> enumerate(const std::string& s) {
    return enumerate(std::vector<char>(s.begin(), s.end()));
}

}  // namespace run_enumerate
