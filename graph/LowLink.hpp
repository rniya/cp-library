/**
 * @brief Low Link (橋/関節点)
 * @docs docs/graph/LowLink.md
 */

#pragma once

#include "../base.hpp"

struct LowLink{
    int n,time;
    vector<int> ord,low;
    vector<vector<int>> G;
    vector<int> articulation;
    vector<pair<int,int>> bridge;
    LowLink(int n):n(n),time(0),ord(n,-1),low(n),G(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bool is_bridge(int u,int v){
        if (ord[u]>ord[v]) swap(u,v);
        return ord[u]<low[v];
    }
    void dfs(int v,int p){
        ord[v]=low[v]=time++;
        bool is_articulation=false;
        int cnt=0;
        for (int u:G[v]){
            if (u==p) continue;
            if (~ord[u]){
                low[v]=min(low[v],ord[u]);
                continue;
            }
            ++cnt;
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            is_articulation|=(~p&&ord[v]<=low[u]);
            if (is_bridge(v,u)) bridge.emplace_back(v,u);
        }
        is_articulation|=(p<0&&cnt>1);
        if (is_articulation) articulation.emplace_back(v);
    }
    void build(){
        for (int v=0;v<n;++v){
            if (ord[v]<0) dfs(v,-1);
        }
    }
};