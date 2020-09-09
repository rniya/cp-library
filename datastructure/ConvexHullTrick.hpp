/**
 * @brief Convex Hull Trick
 * @docs docs/datastructure/ConvexHullTrick
 */

#pragma once

#include "../base.hpp"

template<typename T,bool Mono>
struct ConvexHullTrick{
    typedef function<bool(T,T)> C;
    #define F first
    #define S second
    using Line=pair<T,T>;
    C cmp;
    deque<Line> Lines;
    ConvexHullTrick(C cmp=[](T l,T r){return l>=r;})
        :cmp(cmp){}
    bool check(Line l1,Line l2,Line l3){
        if (l1<l3) swap(l1,l3);
        return (l3.S-l2.S)*(l2.F-l1.F)>=(l2.S-l1.S)*(l3.F-l2.F);
    }
    void add(T a,T b){
        Line line(a,b);
        while(Lines.size()>=2&&check(*(Lines.end()-2)
        ,Lines.back(),line)) Lines.pop_back();
        Lines.emplace_back(line);
    }
    T f(const int &i,const T &x){
        return Lines[i].F*x+Lines[i].S;
    }
    T f(const Line &line,const T &x){
        return line.F*x+line.S;
    }
    T query(T x){
        if (Mono){
            while(Lines.size()>=2
            &&cmp(f(0,x),f(1,x))) Lines.pop_front();
            return f(0,x);
        } else {
            int lb=-1,ub=Lines.size()-1;
            while(ub-lb>1){
                int mid=(lb+ub)>>1;
                (cmp(f(mid,x),f(mid+1,x))?lb:ub)=mid;
            }
            return f(ub,x);
        }
    }
    #undef F
    #undef S
};