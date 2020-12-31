/**
 * @brief
 * @docs docs/graph/RangeEdgeGraph.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
class RangeEdgeGraph{
    struct edge{
        int to; T cost;
        edge(int to,T cost):to(to),cost(cost){}
        bool operator<(const edge &rhs) const {return cost>rhs.cost;}
    };
    int n;
    vector<vector<edge>> G;
    void add_edge(int u,int v,T cost){G[(3*n<=u?u-2*n:u)].emplace_back(v,cost);}

public:
    RangeEdgeGraph(int n):n(n),G(3*n){
        for (int i=1;i<n;++i){
            int l=i<<1|0,r=i<<1|1;
            add_edge(i,l,0);
            add_edge(i,r,0);
            add_edge(l+2*n,i+2*n,0);
            add_edge(r+2*n,i+2*n,0);
        }
    }
    void add_edge(int l1,int r1,int l2,int r2,T cost){
        int add=G.size();
        G.emplace_back();
        for (l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
            if (l1&1) add_edge((l1++)+2*n,add,0);
            if (r1&1) add_edge((--r1)+2*n,add,0);
        }
        for (l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
            if (l2&1) G[add].emplace_back(l2++,cost);
            if (r2&1) G[add].emplace_back(--r2,cost);
        }
    }
    vector<T> build(int s){
        vector<T> dp(G.size(),numeric_limits<T>::max());
        s+=n; dp[s]=0;
        priority_queue<edge> pq;
        pq.emplace(s,dp[s]);
        while (!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.to;
            if (dp[v]<p.cost) continue;
            for (const auto &e:G[v]){
                int u=e.to;
                if (dp[v]+e.cost<dp[u]){
                    dp[u]=dp[v]+e.cost;
                    pq.emplace(u,dp[u]);
                }
            }
        }
        vector<T> res(dp.begin()+n,dp.begin()+2*n);
        return res;
    }
};