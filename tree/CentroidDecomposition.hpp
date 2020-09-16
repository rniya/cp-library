/**
 * @brief Centroid Decomposition
 * @docs docs/tree/CentroidDecomposition.md
 */

#pragma once

#include "../base.hpp"

class CentroidDecomposition{
    vector<vector<int>> G;
    vector<int> sub,centroid;
    inline int dfs(int v,int p){
        sub[v]=1;
        for (int u:G[v]){
            if (u==p||centroid[u]) continue;
            sub[v]+=dfs(u,v);
        }
        return sub[v];
    }
    inline int find(int v,int p,int mid){
        for (int u:G[v]){
            if (u==p||centroid[u]) continue;
            if (sub[u]>mid) return find(u,v,mid);
        }
        return v;
    }
public:
    CentroidDecomposition(int n):G(n),sub(n),centroid(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int build(int r){return find(r,-1,dfs(r,-1)>>1);}
    void disable(int v){centroid[v]=true;}
    void enable(int v){centroid[v]=false;}
    int alive(int v){return !centroid[v];}
    const vector<int> &operator[](int v) const {return G[v];}
};