#include <cassert>
#include <vector>

template <typename T>
std::vector<T> min_plus_convolution_convex_convex(const std::vector<T>& a, const std::vector<T>& b) {
    int n = a.size(), m = b.size();
    assert(n and m);
    for (int i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);
    for (int i = 0; i + 2 < m; i++) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);
    std::vector<T> c(n + m - 1);
    c[0] = a[0] + b[0];
    for (int i = 0, j = 0, k = 1; k < n + m - 1; k++) {
        if (j == m - 1 or (i < n - 1 and a[i + 1] + b[j] < a[i] + b[j + 1]))
            c[k] = a[++i] + b[j];
        else
            c[k] = a[i] + b[++j];
    }
    return c;
}