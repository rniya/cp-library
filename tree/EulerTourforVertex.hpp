/**
 * @brief Euler Tour (部分木に対する操作)
 * @docs dosc/tree/EulerTourforVertex.md
 */

#pragma once

#include "../base.hpp"

class EulerTourforVertex{
    vector<int> ls,rs;
    int time;
    void dfs(int v,int p){
        ls[v]=time++;
        for (int u:G[v]){
            if (u!=p) dfs(u,v);
        }
        rs[v]=time;
    }

public:
    vector<vector<int>> G;
    EulerTourforVertex(int n):ls(n),rs(n),G(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int r=0){
        time=0; dfs(r,-1);
    }
    int idx(int v){return ls[v];}
    template<typename F>
    void exec(int v,F f){
        f(ls[v],rs[v]);
    }
};