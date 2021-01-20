#pragma once
#include "../base.hpp"

/**
 * @brief Trie
 * @docs docs/string/Trie.md
 */
template <int char_size> struct Trie {
    struct TrieNode {
        char c;
        int dep;
        vector<int> nxt, idxs;
        TrieNode(char c, int dep) : c(c), dep(dep), nxt(char_size, -1) {}
    };
    vector<TrieNode> Nodes;
    function<int(char)> ctoi;
    Trie(function<int(char)> ctoi) : ctoi(ctoi) { Nodes.emplace_back('$', 0); }
    inline int& next(int node, int c) { return Nodes[node].nxt[c]; }
    inline int& next(int node, char c) { return next(node, ctoi(c)); }
    void add(const string& s, int x = 0) {
        int node = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int k = ctoi(s[i]);
            if (next(node, k) < 0) {
                next(node, k) = Nodes.size();
                Nodes.emplace_back(s[i], i + 1);
            }
            node = next(node, k);
        }
        Nodes[node].idxs.emplace_back(x);
    }
    int find(const string& s) {
        int node = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int k = ctoi(s[i]);
            if (next(node, k) < 0) return -1;
            node = next(node, k);
        }
        return node;
    }
    template <typename F> void query(const string& s, const F& f, int l) {
        int node = 0;
        for (int i = l; i < (int)s.size(); i++) {
            node = next(node, s[i]);
            if (node < 0) return;
            for (auto& idx : Nodes[node].idxs) f(idx);
        }
    }
    int size() { return Nodes.size(); };
    vector<int> idxs(int node) { return Nodes[node].idxs; }
};