/**
 * @brief Topological Sort
 * @docs docs/graph/TopologicalSort.md
 */

#pragma once

#include "../base.hpp"

struct TopologicalSort{
    vector<vector<int>> G;
    vector<int> seen,order;
    TopologicalSort(int n):G(n),seen(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
    }
    void dfs(int v){
        seen[v]=1;
        for (int u:G[v]){
            if (!seen[u]) dfs(u);
        }
        order.emplace_back(v);
    }
    vector<int> build(){
        for (int i=0;i<G.size();++i){
            if (!seen[i]) dfs(i);
        }
        reverse(order.begin(),order.end());
        return order;
    }
    int operator[](int i){return order[i];}
};