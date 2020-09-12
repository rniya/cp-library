/**
 * @brief Hopcroft Karp
 * @docs docs/flow/HopcroftKarp
 */

#pragma once

#include "../base.hpp"

struct HopcroftKarp{
private:
    int n,m,time;
    vector<vector<int>> G,rG;
    vector<int> match_l,match_r,level,used;
    void bfs(){
        fill(level.begin(),level.end(),-1);
        queue<int> que;
        for (int i=0;i<n;++i){
            if (match_l[i]==-1){
                level[i]=0;
                que.emplace(i);
            }
        }
        while(!que.empty()){
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
    bool dfs(int v){
        used[v]=time;
        for (int u:G[v]){
            int w=match_r[u];
            if (w<0||(used[w]!=time&&level[w]==level[v]+1&&dfs(w))){
                match_r[u]=v; match_l[v]=u;
                return true;
            }
        }
        return false;
    }
public:
    HopcroftKarp(int n,int m):n(n),m(m),G(n),rG(m),match_l(n,-1),match_r(m,-1),level(n),used(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    vector<pair<int,int>> max_matching(){
        while(1){
            bfs(); ++time;
            int f=0;
            for (int i=0;i<n;++i){
                if (match_l[i]<0){
                    f+=dfs(i);
                }
            }
            if (!f) break;
        }
        vector<pair<int,int>> res;
        for (int i=0;i<n;++i){
            if (match_l[i]>=0){
                res.emplace_back(i,match_l[i]);
            }
        }
        return res;
    }
};