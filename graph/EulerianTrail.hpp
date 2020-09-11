/**
 * @brief オイラーグラフ・準オイラーグラフの構築
 * @docs docs/graph/EulerianTrail.md
 */

#pragma once

#include "../base.hpp"

template<bool directed>
struct EulerianTrail{
    vector<vector<pair<int,int>>> G;
    vector<vector<int>> BG;
    vector<pair<int,int>> es;
    vector<int> used,visited,deg;
    EulerianTrail(int n):G(n),BG(n),visited(n,0),deg(n,0){}
    void add_edge(int u,int v){
        int m=es.size();
        es.emplace_back(u,v);
        used.emplace_back(0);
        BG[u].emplace_back(v);
        BG[v].emplace_back(u);
        G[u].emplace_back(v,m);
        ++deg[u];
        if (directed) --deg[v];
        else G[v].emplace_back(u,m),++deg[v];
    }
    void dfs(int v,int &s,int &t,int &check){
        visited[v]=1;
        if (directed){
            if (abs(deg[v])>1) check=0;
            else if (deg[v]==1){
                if (~s) check=0;
                else s=v;
            }
        } else {
            if (deg[v]&1){
                if (s<0) s=v;
                else if (t<0) t=v;
                else check=0;
            }
        }
        for (int u:BG[v]){
            if (visited[u]) continue;
            dfs(u,s,t,check);
        }
    }
    vector<int> go(int s){
        stack<pair<int,int>> st;
        vector<int> ord;
        st.emplace(s,-1);
        while(!st.empty()){
            int v=st.top().first;
            visited[v]=1;
            if (G[v].empty()){
                ord.emplace_back(st.top().second);
                st.pop();
            } else {
                auto e=G[v].back(); G[v].pop_back();
                if (used[e.second]) continue;
                used[e.second]=1;
                st.emplace(e);
            }
        }
        ord.pop_back();
        reverse(ord.begin(),ord.end());
        return ord;
    }
    vector<vector<int>> build(){
        for (int i=0;i<G.size();++i){
            if (directed&&deg[i]!=0) return {};
            if (!directed&&(deg[i]&1)) return {};
        }
        vector<vector<int>> res;
        for (int i=0;i<G.size();++i){
            if (G[i].empty()||visited[i]) continue;
            res.emplace_back(go(i));
        }
        return res;
    }
    vector<vector<int>> build_semi(){
        vector<vector<int>> res;
        for (int i=0;i<G.size();++i){
            if (visited[i]) continue;
            int s=-1,t=-1,check=1;
            dfs(i,s,t,check);
            if (!check) return {};
            res.emplace_back(go(~s?s:i));
            if (res.back().empty()) res.pop_back();
        }
        return res;
    }
    pair<int,int> operator[](int i){return es[i];}
};