struct GeneralMatching {
    GeneralMatching(int n) : n(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
    }

    std::vector<std::pair<int, int>> solve() {
        std::vector<std::pair<int, int>> res;
        return res;
    }

  private:
    int n;
};