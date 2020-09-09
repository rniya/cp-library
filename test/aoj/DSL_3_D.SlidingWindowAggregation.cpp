#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#include "../../base.hpp"
#include "../../datastructure/SlidingWindowAggregation.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,L; cin >> N >> L;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    SlidingWindowAggregation<int> SWAG([](int a,int b){return min(a,b);},INT_MAX);
    for (int i=0;i<L-1;++i) SWAG.push(a[i]);

    for (int i=L-1;i<N;++i){
        SWAG.push(a[i]);
        cout << SWAG.fold() << (i+1==N?'\n':' ');
        SWAG.pop();
    }
}