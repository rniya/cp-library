/**
 * @brief 2部グラフ判定
 * @docs docs/graph/BipartiteGraph.md
 */

#pragma once

#include "../base.hpp"

struct BipartiteGraph{
    vector<vector<int>> G;
    vector<int> color,root;
    BipartiteGraph(int n):G(n),color(n,-1),root(n,-1){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bool dfs(int v,int c,int r){
        color[v]=c; root[v]=r;
        for (int u:G[v]){
            if (color[u]==c) return false;
            if (color[u]<0&&!dfs(u,c^1,r)) return false;
        }
        return true;
    }
    bool build(){
        for (int v=0;v<G.size();++v){
            if (color[v]<0&&!dfs(v,0,v)){
                return false;
            }
        }
        return true;
    }
};