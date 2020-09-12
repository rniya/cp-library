/**
 * @brief Suffix Array
 * @docs docs/string/SuffixArray.hpp
 */

#pragma once

#include "../base.hpp"

struct SuffixArray{
    string s;
    vector<int> SA;
    SuffixArray(const string &S):s(S){
        int n=s.size();
        SA.resize(n);
        iota(SA.begin(),SA.end(),0);
        sort(SA.begin(),SA.end(),[&](int a,int b){
            return s[a]==s[b]?a>b:s[a]<s[b];
        });
        vector<int> nxt(n),c(s.begin(),s.end()),cnt(n);
        for (int j=1;j<n;j<<=1){
            for (int i=0;i<n;++i){
                if (i&&c[SA[i-1]]==c[SA[i]]&&SA[i-1]+j<n&&c[SA[i-1]+j/2]==c[SA[i]+j/2]) nxt[SA[i]]=nxt[SA[i-1]];
                else nxt[SA[i]]=i;
            }
            iota(cnt.begin(),cnt.end(),0);
            copy(SA.begin(),SA.end(),c.begin());
            for (int i=0;i<n;++i){
                int sl=c[i]-j;
                if (sl>=0) SA[cnt[nxt[sl]]++]=sl;
            }
            nxt.swap(c);
        }
    }
    bool lt_substr(const string &t,int si=0,int ti=0){
        int sn=s.size(),tn=t.size();
        for (;si<sn&&ti<tn;++si,++ti){
            if (s[si]<t[ti]) return true;
            if (s[si]>t[ti]) return false;
        }
        return si>=sn&&ti<tn;
    }
    int lower_bound(const string &t){
        int lb=-1,ub=SA.size();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (lt_substr(t,SA[mid])?lb:ub)=mid;
        }
        return ub;
    }
    pair<int,int> lower_upper_bound(string &t){
        int idx=lower_bound(t);
        int lb=idx-1,ub=SA.size();
        ++t.back();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (lt_substr(t,SA[mid])?lb:ub)=mid;
        }
        --t.back();
        return {idx,ub};
    }
    int operator[](int i) const {return SA[i];}
    int size() const {return s.size();}
};