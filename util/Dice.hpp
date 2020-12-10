/**
 * @brief サイコロ
 * @docs docs/util/Dice.md
 */

#pragma once

#include "../base.hpp"

struct Dice{
    int surface[6];
    int top()   {return surface[0];}
    int south() {return surface[1];}
    int east()  {return surface[2];}
    int west()  {return surface[3];}
    int north() {return surface[4];}
    int bottom(){return surface[5];}
    int operator[](int i) const {return surface[i];}
    const int dice[6][6]=   {{0,3,5,2,4,0}
                            ,{4,0,1,6,0,3}
                            ,{2,6,0,0,1,5}
                            ,{5,1,0,0,6,2}
                            ,{3,0,6,1,0,4}
                            ,{0,4,2,5,3,0}};
    const int code[6][4]=   {{0,3,5,2}
                            ,{0,2,5,3}
                            ,{0,1,5,4}
                            ,{0,4,5,1}
                            ,{1,2,4,3}
                            ,{1,3,4,2}};
    const string direction="EWNSRL";
    Dice(int TOP,int FRONT){
        surface[0]=TOP; surface[1]=FRONT; surface[2]=dice[TOP-1][FRONT-1];
        surface[3]=7-surface[2]; surface[4]=7-surface[1]; surface[5]=7-surface[0];
    }
    void roll(char c){
        for (int i=0;i<6;++i){
            if (direction[i]!=c) continue;
            int tmp=surface[code[i][0]];
            surface[code[i][0]]=surface[code[i][1]];
            surface[code[i][1]]=surface[code[i][2]];
            surface[code[i][2]]=surface[code[i][3]];
            surface[code[i][3]]=tmp;
        }
    }
};