/**
 * @brief Hopcroft Karp
 * @docs docs/flow/HopcroftKarp.md
 */

#pragma once

#include "../base.hpp"

struct HopcroftKarp{
private:
    int n,m; bool matched;
    vector<vector<int>> G,rG;
    vector<int> match_l,match_r,level;
    void levelize(){
        queue<int> que;
        for (int i=0;i<n;++i){
            level[i]=-1;
            if (match_l[i]<0){
                level[i]=0;
                que.emplace(i);
            }
        }
        while (!que.empty()){
            int v=que.front(); que.pop();
            for (int u:G[v]){
                int w=match_r[u];
                if (~w&&level[w]<0){
                    level[w]=level[v]+1;
                    que.emplace(w);
                }
            }
        }
    }
    bool find_augumenting_path(int v){
        for (int u:G[v]){
            int w=match_r[u];
            if (w<0||(level[w]>level[v]&&find_augumenting_path(w))){
                match_l[v]=u; match_r[u]=v;
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> build_residual_graph(){
        if (!matched) max_matching();
        const int s=n+m,t=n+m+1;
        vector<vector<int>> res(n+m+2);
        for (int i=0;i<n;++i){
            if (match_l[i]<0){
                res[s].emplace_back(i);
            }
        }
        for (int i=0;i<n;++i){
            for (int j:G[i]){
                if (match_l[i]==j) res[j+n].emplace_back(i);
                else res[i].emplace_back(j+n);
            }
        }
        return res;
    }
    vector<bool> find_residual_path(){
        auto g=build_residual_graph();
        queue<int> que;
        vector<bool> visited(n+m+2);
        que.emplace(n+m); visited[n+m]=true;
        while (!que.empty()){
            int v=que.front(); que.pop();
            for (int u:g[v]){
                if (visited[u]) continue;
                visited[u]=true; que.emplace(u);
            }
        }
        return visited;
    }

public:
    HopcroftKarp(int n,int m):n(n),m(m),G(n),rG(m),match_l(n,-1),match_r(m,-1),level(n),matched(false){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    vector<pair<int,int>> max_matching(){
        matched=true;
        while (1){
            levelize();
            int match=0;
            for (int i=0;i<n;++i){
                if (match_l[i]<0){
                    match+=find_augumenting_path(i);
                }
            }
            if (!match) break;
        }
        vector<pair<int,int>> res;
        for (int i=0;i<n;++i){
            if (~match_l[i]){
                res.emplace_back(i,match_l[i]);
            }
        }
        return res;
    }
    vector<int> min_vertex_cover(){
        auto visited=find_residual_path();
        vector<int> res;
        for (int i=0;i<n+m;++i){
            if (visited[i]^(i<n)){
                res.emplace_back(i);
            }
        }
        return res;
    }
    vector<int> max_independent_set(){
        auto visited=find_residual_path();
        vector<int> res;
        for (int i=0;i<n+m;++i){
            if (visited[i]^(i>=n)){
                res.emplace_back(i);
            }
        }
        return res;
    }
    vector<pair<int,int>> min_edge_cover(){
        auto res=max_matching();
        for (int i=0;i<n;++i){
            if (~match_l[i]) continue;
            if (G[i].empty()) return {};
            res.emplace_back(i,G[i][0]);
        }
        for (int i=0;i<m;++i){
            if (~match_r[i]) continue;
            if (rG[i].empty()) return {};
            res.emplace_back(rG[i][0],i);
        }
        return res;
    }
};