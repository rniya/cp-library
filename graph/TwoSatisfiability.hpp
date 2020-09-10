/**
 * @brief 2-SAT
 * @docs docs/graph/TwoSatisfiability
 */

#pragma once

#include "../base.hpp"
#include "StronglyConnectedComponents.hpp"

struct TwoSatisfiability{
    int n;
    StronglyConnectedComponents SCC;
    TwoSatisfiability(int n):n(n),SCC(n*2){}
    int neg(int v){return (n+v)%(n*2);}
    void add_if(int u,int v){
        SCC.add_edge(u,v);
        SCC.add_edge(neg(v),neg(u));
    }
    void add_or(int u,int v){
        add_if(neg(u),v);
    }
    void add_nand(int u,int v){
        add_if(u,neg(v));
    }
    void set_true(int v){
        SCC.add_edge(neg(v),v);
    }
    void set_false(int v){
        SCC.add_edge(v,neg(v));
    }
    vector<int> build(){
        SCC.build();
        vector<int> res(n);
        for (int i=0;i<n;++i){
            if (SCC[i]==SCC[n+i]) return {};
            res[i]=SCC[i]>SCC[n+i];
        }
        return res;
    }
};