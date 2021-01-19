#pragma once
#include "../base.hpp"
#include "Trie.hpp"

/**
 * @brief Aho Corasick
 * @docs docs/string/AhoCorasick.md
 */
template <int char_size> struct AhoCorasick : Trie<char_size + 1> {
    using Trie<char_size + 1>::Trie;
    using Trie<char_size + 1>::next;
    using Trie<char_size + 1>::ctoi;
    const int FAIL = char_size;
    vector<int> cnt;
    void build(bool heavy = true) {
        auto& Nodes = this->Nodes;
        cnt.resize(Nodes.size());
        for (int i = 0; i < Nodes.size(); i++) {
            cnt[i] = Nodes[i].idxs.size();
        }
        queue<int> que;
        for (int i = 0; i <= char_size; i++) {
            if (~next(0, i)) {
                next(next(0, i), FAIL) = 0;
                que.emplace(next(0, i));
            } else
                next(0, i) = 0;
        }
        while (!que.empty()) {
            auto& node = Nodes[que.front()];
            int fail = node.nxt[FAIL];
            cnt[que.front()] += cnt[fail];
            que.pop();
            for (int i = 0; i < char_size; i++) {
                if (~node.nxt[i]) {
                    next(node.nxt[i], FAIL) = next(fail, i);
                    if (heavy) {
                        auto& u = Nodes[node.nxt[i]].idxs;
                        auto& v = Nodes[next(fail, i)].idxs;
                        vector<int> w;
                        set_union(u.begin(), u.end(), v.begin(), v.end(), back_inserter(w));
                        u = w;
                    }
                    que.emplace(node.nxt[i]);
                } else
                    node.nxt[i] = Nodes[fail].nxt[i];
            }
        }
    }
    map<int, int> match(const string& s, int now = 0) {
        auto& Nodes = this->Nodes;
        map<int, int> res;
        for (auto c : s) {
            now = next(now, ctoi(c));
            for (auto& id : Nodes[now].idxs) res[id]++;
        }
        return res;
    }
    int move(const char& c, int now) {
        while (next(now, ctoi(c)) < 0) now = next(now, FAIL);
        return next(now, ctoi(c));
    }
    pair<long long, int> move(const string& s, int now = 0) {
        long long res = 0;
        for (auto& c : s) {
            int nxt = move(c, now);
            res += cnt[nxt];
            now = nxt;
        }
        return {res, now};
    }
    int count(int node) { return cnt[node]; }
};