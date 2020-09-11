/**
 * @brief Project Selection Problem
 * @docs docs/flow/ProjectSelectionProblem.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
struct ProjectSelectionProblem{
    int s,t;
    T sum=0;
    const T inf=numeric_limits<T>::max()/2;
    Dinic<T,true> D;
    ProjectSelectionProblem(int n):s(n),t(n+1),D(n+2){}
    void x_false_loss(int x,T z){
        D.add_edge(x,t,z);
    }
    void x_false_profit(int x,T z){
        sum+=z;
        x_true_loss(x,z);
    }
    void x_true_loss(int x,T z){
        D.add_edge(s,x,z);
    }
    void x_true_profit(int x,T z){
        sum+=z;
        x_false_loss(x,z);
    }
    void x_false_y_true_loss(int x,int y,T z){
        D.add_edge(x,y,z);
    }
    void x_true_y_false_loss(int x,int y,T z){
        D.add_edge(y,x,z);
    }
    void x_true_y_true_profit(int x,int y,T z){
        sum+=z;
        int w=D.add_vertex();
        x_false_loss(w,z);
        x_true_y_false_loss(w,x,inf);
        x_true_y_false_loss(w,y,inf);
    }
    void x_false_y_false_profit(int x,int y,T z){
        sum+=z;
        int w=D.add_vertex();
        x_true_loss(w,z);
        x_false_y_true_loss(w,x,inf);
        x_false_y_true_loss(w,y,inf);
    }
    T build(){
        return D.max_flow(s,t)-sum;
    }
};