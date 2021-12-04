#pragma once
#include <algorithm>
#include <map>
#include <queue>
#include "Trie.hpp"

template <size_t char_size, char margin = 'a'> struct AhoCorasick : Trie<char_size + 1, margin> {
    void build(bool heavy = true) {
        int n = nodes.size();
        cnt.resize(n);
        for (int i = 0; i < n; i++) cnt[i] = nodes[i].idxs.size();
        std::queue<int> que;
        for (size_t i = 0; i <= char_size; i++) {
            if (~next(0, i)) {
                next(next(0, i), FAIL) = 0;
                que.emplace(next(0, i));
            } else
                next(0, i) = 0;
        }
        while (!que.empty()) {
            auto& cur = nodes[que.front()];
            int fail = cur.nxt[FAIL];
            cnt[que.front()] += cnt[fail];
            que.pop();
            for (size_t i = 0; i < char_size; i++) {
                int& nxt = cur.nxt[i];
                if (nxt < 0) {
                    nxt = next(fail, i);
                    continue;
                }
                next(nxt, FAIL) = next(fail, i);
                if (heavy) {
                    auto& u = nodes[nxt].idxs;
                    auto& v = nodes[next(fail, i)].idxs;
                    std::vector<int> w;
                    std::set_union(u.begin(), u.end(), v.begin(), v.end(), back_inserter(w));
                    u = w;
                }
                que.emplace(nxt);
            }
        }
    }

    long long match(const std::string& s) {
        long long res = 0;
        int cur = 0;
        for (const char& c : s) {
            cur = next(cur, c - margin);
            res += cnt[cur];
        }
        return res;
    }

    std::map<int, int> frequency(const std::string& s) {
        std::map<int, int> res;
        int cur = 0;
        for (const char& c : s) {
            cur = next(cur, c - margin);
            for (auto& idx : nodes[cur].idxs) res[idx]++;
        }
        return res;
    }

    int count(int pos) { return cnt[pos]; }

private:
    using super = Trie<char_size + 1, margin>;
    using super::next;
    using super::nodes;

    const int FAIL = char_size;
    std::vector<int> cnt;
};

/**
 * @brief Aho Corasick
 * @docs docs/string/AhoCorasick.md
 */
