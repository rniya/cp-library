#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T> istream& operator>>(istream& is, vector<T>& v);
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p);
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m);
template <typename T> ostream& operator<<(ostream& os, const set<T>& s);
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s);
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v);
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t);

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    return os;
}

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#define debug(...)                                                                    \
    cerr << " ";                                                                      \
    cerr << #__VA_ARGS__ << ": [" << __LINE__ << ": " << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                      \
    debug_out(__VA_ARGS__)
