#pragma once
#include <bits/stdc++.h>

template <typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p);
template <typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& m);
template <typename T> std::ostream& operator<<(std::ostream& os, const std::set<T>& s);
template <typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s);
template <typename T> std::ostream& operator<<(std::ostream& os, const std::deque<T>& v);
template <typename... Args> std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t);

template <typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> std::ostream& operator<<(std::ostream& os, const std::multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> std::ostream& operator<<(std::ostream& os, const std::deque<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    return os;
}

template <int i, typename T> void print_tuple(std::ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(std::ostream& os, const T& t) {
    if (i) os << ',';
    os << std::get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
    os << '{';
    print_tuple<0, std::tuple<Args...>, Args...>(os, t);
    return os << '}';
}

void debug_out() { std::cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    std::cerr << head;
    if (sizeof...(Tail) > 0) std::cerr << ", ";
    debug_out(std::move(tail)...);
}
#define debug(...)                                                                         \
    std::cerr << " ";                                                                      \
    std::cerr << #__VA_ARGS__ << ": [" << __LINE__ << ": " << __FUNCTION__ << "]" << '\n'; \
    std::cerr << " ";                                                                      \
    debug_out(__VA_ARGS__)
