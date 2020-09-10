/**
 * @brief Kruskal
 * @docs docs/graph/Kruskal.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
struct Kruskal{
private:
    struct edge{
        int from,to,used,id; T cost;
        edge(int from,int to,T cost,int id):
            from(from),to(to),cost(cost),id(id),used(0){}
        bool operator<(const edge &e) const{
            if (cost!=e.cost) return cost<e.cost;
            else if (from!=e.from) return from<e.from;
            else return to<e.to;
        }
    };
    vector<edge> es;
    vector<int> par,rank;
    int root(int x){
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    bool merge(int x, int y){
        x=root(x),y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        return true;
    }
    bool same(int x, int y){return root(x)==root(y);}
    int size(int x){return rank[root(x)];}
public:
    Kruskal(int n):par(n),rank(n,1){
        iota(par.begin(),par.end(),0);
    }
    void add_edge(int u,int v,T c,int id=0){
        es.emplace_back(u,v,c,id);
    }
    T build(){
        sort(es.begin(),es.end());
        T res=0;
        for (auto &e:es){
            if (!same(e.from,e.to)){
                res+=e.cost; e.used=1;
                merge(e.from,e.to);
            }
        }
        return res;
    }
    vector<int> restore(T &c){
        int m=es.size();
        vector<int> res(m);
        for (int i=0;i<m;++i) res[es[i].id]=es[i].used;
        return res;
    }
};