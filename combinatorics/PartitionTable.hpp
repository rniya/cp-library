/**
 * @brief 分割数テーブル
 * @docs docs/combinatorics/Partitiontable.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
vector<vector<T>> partition_table(int n,int k){
    vector<vector<T>> dp(n+1,vector<T>(k+1));
    dp[0][0]=1;
    for (int i=0;i<=n;++i){
        for (int j=1;j<=k;++j){
            dp[i][j]=dp[i][j-1]+(i-j>=0?dp[i-j][j]:0);
        }
    }
    return dp;
}