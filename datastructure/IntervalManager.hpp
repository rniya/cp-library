#pragma once
#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

template <typename S, typename T> struct IntervalManager {
    struct node {
        T l, r;
        S x;
        node(T l, T r, S x) : l(l), r(r), x(x) {}
        constexpr bool operator<(const node& rhs) const { return l != rhs.l ? l < rhs.l : r < rhs.r; }
    };

    const S id = S();
    std::set<node> s;

    IntervalManager() {}

    IntervalManager(const std::vector<S>& v) {
        std::vector<node> tmp;
        for (size_t l = 0; l < v.size();) {
            size_t r = l;
            while (r < v.size() and v[l] == v[r]) r++;
            tmp.emplace_back(l, r, v[l]);
            l = r;
        }
        s = std::set<node>(tmp.begin(), tmp.end());
    }

    typename std::set<node>::iterator getItr(const T& x) const {
        auto itr = s.upper_bound(node(x, std::numeric_limits<T>::max(), id));
        if (itr == s.begin()) return s.end();
        itr = prev(itr);
        return itr->l <= x and x < itr->r ? itr : s.end();
    }

    node getSeg(const T& x) const {
        auto itr = getItr(x);
        return itr != s.end() ? *itr : node(x, x + 1, id);
    }

    S get(const T& x) const {
        auto seg = getSeg(x);
        return seg.x;
    }

    S operator[](const T& x) const { return get(x); }

    template <typename ADD, typename DEL> void apply(T l, T r, const S& x, const ADD& add, const DEL& del) {
        auto itr = s.lower_bound(node(l, std::numeric_limits<T>::min(), id));
        while (itr != s.end() and itr->l <= r) {
            if (itr->l == r) {
                if (itr->x == x) {
                    del(itr->l, itr->r, itr->x);
                    r = itr->r;
                    itr = s.erase(itr);
                }
                break;
            }
            if (itr->r <= r) {
                del(itr->l, itr->r, itr->x);
                itr = s.erase(itr);
            } else {
                if (itr->x == x) {
                    r = itr->r;
                    del(itr->l, itr->r, itr->x);
                    itr = s.erase(itr);
                } else {
                    del(itr->l, r, itr->x);
                    node tmp = *itr;
                    itr = s.erase(itr);
                    itr = s.emplace_hint(itr, r, tmp.r, tmp.x);
                }
            }
        }

        if (itr != s.begin()) {
            itr = prev(itr);
            if (itr->r == l) {
                if (itr->x == x) {
                    del(itr->l, itr->r, itr->x);
                    l = itr->l;
                    itr = s.erase(itr);
                }
            } else if (l < itr->r) {
                if (itr->x == x) {
                    del(itr->l, itr->r, itr->x);
                    l = std::min(l, itr->l);
                    r = std::max(r, itr->r);
                    itr = s.erase(itr);
                } else {
                    if (r < itr->r) {
                        itr = s.emplace_hint(next(itr), r, itr->r, itr->x);
                        itr = prev(itr);
                    }
                    del(l, std::min(r, itr->r), itr->x);
                    node tmp = *itr;
                    itr = s.erase(itr);
                    itr = s.emplace_hint(itr, tmp.l, l, tmp.x);
                }
            }
        }

        add(l, r, x);
        s.emplace(l, r, x);
    }

    void apply(T l, T r, const S& x) {
        apply(
            l, r, x, [](T, T, S) {}, [](T, T, S) {});
    }

    friend std::ostream& operator<<(std::ostream& os, const IntervalManager& im) {
        for (const auto& e : im) os << "([" << e.l << ", " << e.r << "): " << e.x << ") ";
        os << "\n";
        return os;
    }
};
