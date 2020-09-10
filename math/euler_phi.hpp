/**
 * @brief Eulerのφ関数
 * @docs docs/math/euler_phi.md
 */

#include "../base.hpp"

template<typename T>
T euler_phi(T n){
    T res=n;
    for (T i=2;i*i<=n;++i) if (n%i==0){
        res-=res/i;
        while (n%i==0) n/=i;
    }
    if (n!=1) res-=res/n;
    return res;
}
vector<int> euler_phi_table(int n){
    vector<int> euler(n+1);
    iota(euler.begin(),euler.end(),0);
    for (int i=2;i<=n;++i) if (euler[i]==i){
        for (int j=i;j<=n;j+=i) euler[j]-=euler[j]/i;
    }
    return euler;
};