#pragma once
#include <functional>
#include <stack>

template <typename Monoid> struct SlidingWindowAggregation {
    typedef std::function<Monoid(Monoid, Monoid)> F;
    std::stack<std::pair<Monoid, Monoid>> front_stack, back_stack;
    F f;
    Monoid id;
    SlidingWindowAggregation(F f, Monoid id) : f(f), id(id), front_stack(), back_stack() {
        front_stack.emplace(id, id);
        back_stack.emplace(id, id);
    }
    void push(const Monoid& x) { back_stack.emplace(x, f(back_stack.top().second, x)); }
    void pop() {
        if (front_stack.size() == 1) {
            while (1 < (int)back_stack.size()) {
                Monoid t = back_stack.top().first;
                Monoid calc = f(t, front_stack.top().second);
                front_stack.emplace(t, calc);
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
    Monoid fold() { return f(front_stack.top().second, back_stack.top().second); }
};
