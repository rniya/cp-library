#include <cassert>
#include <functional>
#include <utility>

template <typename T, bool get_min = true>
std::pair<long long, T> golden_section_search(const std::function<T(long long)>& f, long long mini, long long maxi) {
    assert(mini <= maxi);
    long long a = mini - 1, x, b;
    {
        long long s = 1, t = 2;
        while (t < maxi - mini + 2) std::swap(s += t, t);
        x = a + t - s, b = a + t;
    }
    T fx = f(x), fy;
    while (a + b != 2 * x) {
        long long y = a + b - x;
        fy = f(y);
        if (maxi < y or (get_min ? fx < fy : fx > fy)) {
            b = a;
            a = y;
        } else {
            a = x;
            x = y;
            fx = fy;
        }
    }
    return {x, fx};
}
