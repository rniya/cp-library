/**
 * @brief Strongly Connected Components
 * @docs docs/graph/StronglyConnectedComponents.md
 */

#pragma once

#include "../base.hpp"

struct StronglyConnectedComponents{
    vector<vector<int>> G,rG,C,T;
    vector<int> vs,cmp,used;
    StronglyConnectedComponents(int n):G(n),rG(n),cmp(n),used(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int v){
        used[v]=1;
        for (int u:G[v]) if(!used[u]) dfs(u);
        vs.emplace_back(v);
    }
    void rdfs(int v,int k){
        used[v]=1;
        cmp[v]=k;
        C[k].emplace_back(v);
        for (int u:rG[v]) if (!used[u]) rdfs(u,k);
    }
    int build(){
        int n=G.size();
        for (int i=0;i<n;++i) if (!used[i]) dfs(i);
        fill(used.begin(),used.end(),0);
        int k=0;
        for (int i=n-1;i>=0;--i){
            if (!used[vs[i]]){
                C.emplace_back(),T.emplace_back();
                rdfs(vs[i],k++);
            }
        }
        for (int v=0;v<n;++v){
            for (int u:G[v]){
                if (cmp[v]!=cmp[u]){
                    T[cmp[v]].emplace_back(cmp[u]);
                }
            }
        }
        for (int i=0;i<k;++i){
            sort(T[i].begin(),T[i].end());
            T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
        }
        return k;
    }
    int operator[](int i) const{return cmp[i];}
};