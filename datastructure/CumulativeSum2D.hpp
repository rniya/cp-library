#pragma once
#include "../base.hpp"

/**
 * @brief 2次元累積和
 * @docs docs/datastructure/CumulativeSum2D.md
 */
template <typename T> struct CumulativeSum2D {
    vector<vector<T>> dat;
    CumulativeSum2D(const vector<vector<T>>& v) {
        int H = v.size(), W = v[0].size();
        dat.assign(H + 1, vector<T>(W + 1, 0));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                dat[i + 1][j + 1] = v[i][j];
                dat[i + 1][j + 1] += dat[i + 1][j] + dat[i][j + 1] - dat[i][j];
            }
        }
    }
    T query(int sx, int gx, int sy, int gy) {  // [sx,gx),[sy,gy)
        return dat[gx][gy] - dat[sx][gy] - dat[gx][sy] + dat[sx][sy];
    }
};