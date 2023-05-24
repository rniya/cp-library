// https://ei1333.github.io/library/other/offline-dynamic-connectivity.hpp
// https://suisen-cp.github.io/cp-library-cpp/library/algorithm/offline_dynamic_connectivity.hpp

#include <utility>
#include "datastructure/UndoUnionFind.hpp"

struct OfflineDynamicConnectivity {
    OfflineDynamicConnectivity(int n) : n(n) {}

    void add(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
    }

    void del(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
    }

    void same(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
    }

    std::vector<bool> run() {
        int q = qs.size();
        std::vector<bool> res(q);
        auto dfs = [&](auto self, int k) -> void {

        };
        dfs(dfs, 1);
        return res;
    }

  private:
    int n;
    std::vector<std::pair<int, int>> qs;
};
