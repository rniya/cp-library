#include <cassert>
#include <limits>
#include <utility>
#include <vector>

template <class Cost> std::pair<Cost, std::vector<int>> hungarian(const std::vector<std::vector<Cost>>& a) {
    const Cost inf = std::numeric_limits<Cost>::max();
    int n = a.size(), m = a[0].size();
    assert(n <= m);
    std::vector<int> P(m + 1, -1);
    std::vector<Cost> yl(n, 0), yr(m + 1, 0);
    for (int i = 0; i < n; i++) {
        std::vector<Cost> adjmin(m + 1, inf);
        std::vector<bool> inL(m + 1, false);
        std::vector<int> pre(m + 1, -1);
        int j_cur = m;
        P[j_cur] = i;
        while (P[j_cur] != -1) {
            inL[j_cur] = true;
            int i_cur = P[j_cur], j_nxt = 0;
            Cost delta = inf;
            for (int j = 0; j < m; j++) {
                if (inL[j]) continue;
                Cost w = a[i_cur][j] - yl[i_cur] - yr[j];
                if (w < adjmin[j]) adjmin[j] = w, pre[j] = j_cur;
                if (adjmin[j] < delta) delta = adjmin[j], j_nxt = j;
            }
            for (int j = 0; j <= m; j++) {
                if (inL[j])
                    yl[P[j]] += delta, yr[j] -= delta;
                else
                    adjmin[j] -= delta;
            }
            j_cur = j_nxt;
        }
        for (; j_cur != m; j_cur = pre[j_cur]) P[j_cur] = P[pre[j_cur]];
    }
    std::vector<int> res(n);
    for (int i = 0; i < m; i++) {
        if (P[i] != -1) {
            res[P[i]] = i;
        }
    }
    return {-yr[m], res};
}
