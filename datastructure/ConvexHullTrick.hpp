/**
 * @brief Convex Hull Trick
 * @docs docs/datastructure/ConvexHullTrick.md
 */

#pragma once

#include "../base.hpp"

template<typename T,bool isMin=true>
struct ConvexHullTrick{
    struct Line{
        T a,b;
        Line(T a,T b):a(a),b(b){}
    };
    deque<Line> Lines;
    bool empty() const {return Lines.empty();}
    inline int sgn(T a){return a==0?0:(a<0?-1:1);}
    inline bool check(const Line &a,const Line &b,const Line &c){
        if (b.b==a.b||c.b==b.b) return sgn(b.a-a.a)*sgn(c.b-b.b)>=sgn(c.a-b.a)*sgn(b.b-a.b);
        return (long double)(b.a-a.a)*sgn(c.b-b.b)/(long double)abs(b.b-a.b)>=(long double)(c.a-b.a)*sgn(b.b-a.b)/(long double)abs(c.b-b.b);
    }
    void add(T a,T b){
        if (!isMin) a*=-1,b*=-1;
        Line l(a,b);
        if (empty()){
            Lines.emplace_back(l);
            return;
        }
        if (Lines.front().a<=a){
            if (Lines.front().a==a){
                if (Lines.front().b<=b) return;
                Lines.pop_front();
            }
            while(Lines.size()>=2&&check(l,Lines.front(),Lines[1])) Lines.pop_front();
            Lines.emplace_front(l);
        } else {
            if (Lines.back().a==a){
                if (Lines.back().b<=b) return;
                Lines.pop_back();
            }
            while(Lines.size()>=2&&check(Lines[Lines.size()-2],Lines.back(),l)) Lines.pop_back();
            Lines.emplace_back(l);
        }
    }
    inline T f(const Line &l,const T &x){
        return l.a*x+l.b;
    }
    T query(T x){
        int lb=-1,ub=Lines.size()-1;
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (f(Lines[mid],x)>=f(Lines[mid+1],x)?lb:ub)=mid;
        }
        return (isMin?f(Lines[ub],x):-f(Lines[ub],x));
    }
    T query_monotone_inc(T x){
        while(Lines.size()>=2&&f(Lines.front(),x)>=f(Lines[1],x)) Lines.pop_front();
        return (isMin?f(Lines.front(),x):-f(Lines.front(),x));
    }
    T query_monotone_dec(T x){
        while(Lines.size()>=2&&f(Lines.back(),x)>=f(Lines[Lines.size()-2],x)) Lines.pop_back();
        return (isMin?f(Lines.back(),x):-f(Lines.back(),x));
    }
};