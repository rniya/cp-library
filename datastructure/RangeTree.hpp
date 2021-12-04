#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

template <typename structure_t, typename value_t, typename coordinate_t> struct RangeTree {
private:
    using structure_new = std::function<structure_t*(int)>;
    using structure_set = std::function<void(structure_t&, int, value_t)>;
    using structure_prod = std::function<value_t(structure_t&, int, int)>;
    using value_merge = std::function<value_t(value_t, value_t)>;
    using Pt = std::pair<coordinate_t, coordinate_t>;

public:
    RangeTree(const structure_new& st_new,
              const structure_set& st_set,
              const structure_prod& st_prod,
              const value_merge& op,
              const value_t& e)
        : st_new(st_new), st_set(st_set), st_prod(st_prod), op(op), e(e) {}

    void add_point(coordinate_t x, coordinate_t y) { points.emplace_back(x, y); }

    void build() {
        std::sort(points.begin(), points.end());
        points.erase(std::unique(points.begin(), points.end()), points.end());
        n = points.size();
        yxs.resize(n << 1);
        segs.resize(n << 1, nullptr);
        for (int i = 0; i < n; i++) yxs[n + i] = {{points[i].second, points[i].first}};
        for (int i = n - 1; i >= 0; i--) {
            auto& lch = yxs[i << 1 | 0];
            auto& rch = yxs[i << 1 | 1];
            std::merge(lch.begin(), lch.end(), rch.begin(), rch.end(), std::back_inserter(yxs[i]));
            yxs[i].erase(std::unique(yxs[i].begin(), yxs[i].end()), yxs[i].end());
        }
        for (int i = 0; i < (n << 1); i++) segs[i] = st_new(yxs[i].size());
    }

    void set(coordinate_t x, coordinate_t y, value_t val) {
        int i = std::distance(points.begin(), std::lower_bound(points.begin(), points.end(), std::make_pair(x, y)));
        assert(i < n && points[i] == std::make_pair(x, y));
        for (i += n; i; i >>= 1) st_set(*segs[i], zip(i, x, y), val);
    }

    value_t prod(coordinate_t xl, coordinate_t xr, coordinate_t yl, coordinate_t yr) {
        assert(xl <= xr && yl <= yr);
        value_t L = e, R = e;
        int l = zip(xl), r = zip(xr);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = op(L, st_prod(*segs[l], zip(l, yl), zip(l, yr))), l++;
            if (r & 1) --r, R = op(st_prod(*segs[r], zip(r, yl), zip(r, yr)), R);
        }
        return op(L, R);
    }

private:
    int n;
    const structure_new st_new;
    const structure_set st_set;
    const structure_prod st_prod;
    const value_merge op;
    const value_t e;
    std::vector<Pt> points;
    std::vector<std::vector<Pt>> yxs;
    std::vector<structure_t*> segs;

    int zip(coordinate_t x) {
        auto compare = [](const Pt& l, const Pt& r) { return l.first < r.first; };
        return std::distance(
            points.begin(), std::lower_bound(points.begin(), points.end(), std::make_pair(x, coordinate_t()), compare));
    }

    int zip(int i, coordinate_t y) {
        auto compare = [](const Pt& l, const Pt& r) { return l.first < r.first; };
        return std::distance(
            yxs[i].begin(), std::lower_bound(yxs[i].begin(), yxs[i].end(), std::make_pair(y, coordinate_t()), compare));
    }

    int zip(int i, coordinate_t x, coordinate_t y) {
        return std::distance(yxs[i].begin(), std::lower_bound(yxs[i].begin(), yxs[i].end(), std::make_pair(y, x)));
    }
};

/**
 * @brief Range Tree (抽象化領域木)
 * @docs docs/datastructure/RangeTree.md
 */
