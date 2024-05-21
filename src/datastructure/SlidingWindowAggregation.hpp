#pragma once
#include <functional>
#include <stack>

template <class S, S (*op)(S, S), S (*e)()> struct SlidingWindowAggregation {
    std::stack<std::pair<S, S>> front_stack, back_stack;
    SlidingWindowAggregation() : front_stack(), back_stack() {
        front_stack.emplace(e(), e());
        back_stack.emplace(e(), e());
    }
    void push(const S& x) { back_stack.emplace(x, op(back_stack.top().second, x)); }
    void pop() {
        if (front_stack.size() == 1) {
            while (1 < (int)back_stack.size()) {
                S t = back_stack.top().first;
                S calc = op(t, front_stack.top().second);
                front_stack.emplace(t, calc);
                back_stack.pop();
            }
        }
        front_stack.pop();
    }
    S fold() { return op(front_stack.top().second, back_stack.top().second); }
};
