#pragma once
#include "../base.hpp"

/**
 * @brief 文字列の2進変換
 * @docs docs/util/binary_conversion.md
 */

vector<bool> binary_conversion(const string& s) {
    using u64 = uint64_t;

    vector<u64> num(s.size() / 9 + 10, 0);
    for (size_t i = 0; i < s.size(); i += 9) {
        const string t = s.substr(i, 9);
        u64 add = 0, mul = 1;
        for (const auto c : t) {
            add = add * 10 + (c - '0');
            mul *= 10;
        }
        for (auto& d : num) {
            d = d * mul + add;
            add = d >> 32;
            d -= add << 32;
        }
    }

    vector<bool> res(num.size() * 32);
    for (size_t i = 0; i < num.size(); i++) {
        for (size_t j = 0; j < 32; j++) {
            res[i * 32 + j] = num[i] >> j & 1;
        }
    }

    while (!res.empty() && !res.back()) res.pop_back();
    return res;
};