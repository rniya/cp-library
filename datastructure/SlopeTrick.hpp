#pragma once
#include <cassert>
#include <limits>
#include <queue>

template <typename T> struct SlopeTrick {
    // initialize as f(x) = 0
    SlopeTrick() : min_f(0), add_l(0), add_r(0) {}

    // argmin f(x), min f(x)
    std::tuple<T, T, T> query() const { return {top_L(), top_R(), min_f}; }

    // f(x) += b
    void add_const(const T& b) { min_f += b; }

    // f(x) += max(a - x, 0) \_
    void add_a_minus_x(const T& a) {
        min_f += std::max(T(0), a - top_R());
        push_R(a);
        push_L(pop_R());
    }

    // f(x) += max(x - a, 0) _/
    void add_x_minus_a(const T& a) {
        min_f += std::max(T(0), top_L() - a);
        push_L(a);
        push_R(pop_L());
    }

    // f(x) += |x - a| \/
    void add_abs(const T& a) {
        add_a_minus_x(a);
        add_x_minus_a(a);
    }

    // f(x) <- min_{y <= x} f(y) \/ -> \_
    void chmin_right() {
        while (!R.empty()) R.pop();
    }

    // f(x) <- min_{x <= y} f(y)
    void chmin_left() {
        while (!L.empty()) L.pop();
    }

    // f(x) <- min_{x - b <= y <= x - a} f(y)
    void shift(const T& a, const T& b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }

    // f(x) <- f(x - a)
    void shift(const T& a) { shift(a, a); }

    // return f(x), f destructive
    T get_destructive(const T& x) {
        T res = min_f;
        while (!L.empty()) res += std::max(T(0), pop_L() - x);
        while (!R.empty()) res += std::max(T(0), x - pop_R());
        return res;
    }

    // f(x) += g(x), g destructive
    void merge_destructive(SlopeTrick& g) {
        if (g.size() < size()) {
            std::swap(min_f, g.min_f);
            std::swap(L, g.L);
            std::swap(R, g.R);
            std::swap(min_f, g.add_l);
            std::swap(min_f, g.add_r);
        }
        min_f += g.min_f;
        while (!g.L.empty()) add_a_minus_x(g.pop_L());
        while (!g.R.empty()) add_x_minus_a(g.pop_R());
    }

private:
    const T inf = std::numeric_limits<T>::max() / 2;
    T min_f;
    std::priority_queue<T, std::vector<T>, std::less<>> L;
    std::priority_queue<T, std::vector<T>, std::greater<>> R;
    T add_l, add_r;

    void push_L(const T& a) { L.emplace(a - add_l); }

    T top_L() const { return L.empty() ? -inf : L.top() + add_l; }

    T pop_L() {
        T res = top_L();
        if (!L.empty()) L.pop();
        return res;
    }

    void push_R(const T& a) { R.emplace(a - add_r); }

    T top_R() const { return R.empty() ? inf : R.top() + add_r; }

    T pop_R() {
        T res = top_R();
        if (!R.empty()) R.pop();
        return res;
    }

    size_t size() const { return L.size() + R.size(); }
};

/**
 * @brief Slope Trick
 * @docs docs/datastructure/SlopeTrick.md
 */
