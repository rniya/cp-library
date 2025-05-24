#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <string>
#include <vector>

template <size_t char_size, char margin = 'a'> struct Trie {
    struct Node {
        std::array<int, char_size> nxt;
        std::vector<int> idxs;
        int idx, sub;
        char key;
        Node(char c) : idx(-1), sub(0), key(c) { std::fill(nxt.begin(), nxt.end(), -1); }
    };

    std::vector<Node> nodes;

    inline int& next(int i, int j) { return nodes[i].nxt[j]; }

    Trie() { nodes.emplace_back('$'); }

    void add(const std::string& s, int x = 0) {
        int cur = 0;
        for (const char& c : s) {
            int k = c - margin;
            if (next(cur, k) < 0) {
                next(cur, k) = nodes.size();
                nodes.emplace_back(c);
            }
            cur = next(cur, k);
            nodes[cur].sub++;
        }
        nodes[cur].idx = x;
        nodes[cur].idxs.emplace_back(x);
    }

    int find(const std::string& s) {
        int cur = 0;
        for (const char& c : s) {
            int k = c - margin;
            if (next(cur, k) < 0) return -1;
            cur = next(cur, k);
        }
        return cur;
    }

    int move(int pos, char c) {
        assert(pos < (int)nodes.size());
        return pos < 0 ? -1 : next(pos, c - margin);
    }

    int size() const { return nodes.size(); }

    int idx(int pos) { return pos < 0 ? -1 : nodes[pos].idx; }

    std::vector<int> idxs(int pos) { return pos < 0 ? std::vector<int>() : nodes[pos].idxs; }
};
