#pragma once
#include "../base.hpp"

/**
 * @brief SLope Trick
 * @docs docs/datastructure/SlopeTrick.md
 */
template <typename T> class SlopeTrick {
    const T inf = numeric_limits<T>::max() / 3;
    T min_f;
    priority_queue<T, vector<T>, less<>> L;
    priority_queue<T, vector<T>, greater<>> R;
    T add_l, add_r;

    void push_L(const T& x) { L.emplace(x - add_l); }
    T top_L() const { return !L.empty() ? L.top() + add_l : -inf; }
    T pop_L() {
        T res = top_L();
        if (!L.empty()) L.pop();
        return res;
    }
    void clear_left() {
        while (!L.empty()) L.pop();
    }
    void push_R(const T& x) { R.emplace(x - add_r); }
    T top_R() const { return !R.empty() ? R.top() + add_r : inf; }
    T pop_R() {
        T res = top_R();
        if (!R.empty()) R.pop();
        return res;
    }
    void clear_right() {
        while (!R.empty()) R.pop();
    }
    size_t size() const { return L.size() + R.size(); }

public:
    SlopeTrick() : min_f(0), add_l(0), add_r(0) {}
    tuple<T, T, T> query() const { return make_tuple(top_L(), top_R(), min_f); }
    // f(x) += a
    void add_all(const T& a) { min_f += a; }
    // add _/
    // f(x) += max(x - a, 0)
    void add_x_minus_a(const T& a) {
        min_f += max(top_L() - a, T(0));
        push_L(a);
        push_R(pop_L());
    }
    // add \_
    // f(x) += max(a - x, 0)
    void add_a_minus_x(const T& a) {
        min_f += max(a - top_R(), T(0));
        push_R(a);
        push_L(pop_R());
    }
    // add \/
    // f(x) += abs(x - a)
    void add_abs(const T& a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }

    // \/ -> \_
    // f(x) <- min_{y <= x} f(y)
    void cumulative_min_left() { clear_right(); }
    // \/ -> _/
    // f(x) <- min_{x <= y} f(y)
    void cumulative_min_right() { clear_left(); }

    // f(x) <- min_{x- b <= y <= x - a} f(y)
    void shift(const T& a, const T& b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }
    // f(x) <- f(x - a)
    // note after this operation, L and R are empty
    void shift(const T& a) { shift(a, a); }

    T get(const T& x) {
        T res = min_f;
        while (!L.empty()) res += max(pop_L() - x, T(0));
        while (!R.empty()) res += max(x - pop_R(), T(0));
        return res;
    }
};