/**
 * @brief Heavy Light Decomposition
 * @docsdocs/tree/HeavyLightDecomposition.md
 */

#pragma once

#include "../base.hpp"

class HeavyLightDecomposition{
    void dfs_sz(int v){
        if (G[v].size()&&G[v][0]==par[v]) swap(G[v][0],G[v].back());
        for (int &u:G[v]){
            if (u==par[v]) continue;
            par[u]=v; dep[u]=dep[v]+1;
            dfs_sz(u);
            sub[v]+=sub[u];
            if (sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
        }
    }
    void dfs_hld(int v,int c,int &times){
        vid[v]=times++; type[v]=c;
        for (int u:G[v]){
            if (u==par[v]) continue;
            head[u]=(u==G[v][0]?head[v]:u);
            dfs_hld(u,c,times);
        }
    }
public:
    vector<vector<int>> G;
    vector<int> vid,head,sub,par,dep,type;
    HeavyLightDecomposition(int n):
        G(n),vid(n,-1),head(n),sub(n,1),par(n,-1),dep(n,0),type(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(vector<int> rs={0}){
        int c=0,times=0;
        for (int r:rs){
            dfs_sz(r);
            head[r]=r;
            dfs_hld(r,c++,times);
        }
    }
    int lca(int u,int v){
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v);
            if (head[u]==head[v]) return u;
        }
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    template<typename F>
    void update_path(int u,int v,const F &f,bool edge=false){
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v);
            if (head[u]==head[v]) break;
            f(vid[head[v]],vid[v]+1);
        }
        f(vid[u]+edge,vid[v]+1);
    }
    template<typename F>
    void update_sub(int u,const F &f,bool edge=false){
        f(vid[u]+edge,vid[u]+sub[u]);
    }
    template<typename T,typename Q,typename F>
    T query(int u,int v,const T &id,const Q &q,const F &f,bool edge=false){
        T l=id,r=id;
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v),swap(l,r);
            if (head[u]==head[v]) break;
            l=f(l,q(vid[head[v]],vid[v]+1));
        }
        return f(r,f(l,q(vid[u]+edge,vid[v]+1)));
    }
};