/**
 * @brief Primal Dual
 * @docs docs/flow/PrimalDual.md
 */

#pragma once

#include "../base.hpp"

template<typename T,typename E>
struct PrimalDual{
    const E inf=numeric_limits<E>::max();
    struct edge{
        int to,rev; T cap; E cost;
        edge(int to,T cap,E cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
    };
    vector<vector<edge>> G;
    vector<pair<int,int>> pos;
    vector<E> h,dist;
    vector<int> prevv,preve;
    PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}
    int add_edge(int from,int to,T cap,E cost){
        pos.emplace_back(from,G[from].size());
        G[from].emplace_back(to,cap,cost,G[to].size());
        G[to].emplace_back(from,0,-cost,G[from].size()-1);
        return pos.size()-1;
    }
    tuple<int,int,int,int,int> get_edge(int i){
        auto e=G[pos[i].first][pos[i].second];
        auto re=G[e.to][e.rev];
        return {pos[i].first,e.to,e.cap+re.cap,re.cap,e.cost};
    }
    vector<tuple<int,int,int,int,int>> edges(){
        vector<tuple<int,int,int,int,int>> res;
        for (int i=0;i<pos.size();++i){
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    void dijkstra(int s){
        struct P{
            E c; int v;
            P(E c,int v):c(c),v(v){}
            bool operator<(const P &rhs) const {return c>rhs.c;}
        };
        priority_queue<P> pq;
        fill(dist.begin(),dist.end(),inf);
        dist[s]=0; pq.emplace(dist[s],s);
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.v;
            if (dist[v]<p.c) continue;
            for (int i=0;i<G[v].size();++i){
                auto &e=G[v][i];
                if (e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v; preve[e.to]=i;
                    pq.emplace(dist[e.to],e.to);
                }
            }
        }
    }
    vector<pair<T,E>> slope(int s,int t,T lim){
        T f=0; E c=0,pre=-1;
        vector<pair<T,E>> res;
        res.emplace_back(f,c);
        while(f<lim){
            dijkstra(s);
            if (dist[t]==inf) break;
            for (int v=0;v<G.size();++v) h[v]+=dist[v];
            T d=lim-f;
            for (int v=t;v!=s;v=prevv[v]){
                d=min(d,G[prevv[v]][preve[v]].cap);
            }
            for (int v=t;v!=s;v=prevv[v]){
                auto &e=G[prevv[v]][preve[v]];
                e.cap-=d; G[v][e.rev].cap+=d;
            }
            f+=d; c+=h[t]*d;
            if (pre==h[t]) res.pop_back();
            res.emplace_back(f,c);
            pre=c;
        }
        return res;
    }
    E min_cost_flow(int s,int t,T f){
        auto res=slope(s,t,f).back();
        return res.first==f?res.second:-1;
    }
    pair<T,E> min_cost_max_flow(int s,int t){
        return slope(s,t,numeric_limits<T>::max()).back();
    }
    vector<pair<T,E>> min_cost_slope(int s,int t){
        return slope(s,t,numeric_limits<T>::max());
    }
};