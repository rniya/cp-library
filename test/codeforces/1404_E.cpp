#define IGNORE

#define PROBLEM "https://codeforces.com/contest/1404/problem/E"

#include "../../base.hpp"
#include "../../flow/ProjectSelectionProblem.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<string> S(n);
    for (int i=0;i<n;++i) cin >> S[i];

    ProjectSelectionProblem<int> PSP(n*m);
    auto id=[&](int x,int y){return x*m+y;};
    int ans=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (S[i][j]!='#') continue;
            ++ans;
            for (int k=0;k<2;++k){
                int nx=i+(k^1),ny=j+k;
                if (n<=nx||m<=ny) continue;
                if (S[nx][ny]!='#') continue;
                if (!k) PSP.x_true_y_true_profit(id(i,j),id(nx,ny),1);
                else PSP.x_false_y_false_profit(id(i,j),id(nx,ny),1);
            }
        }
    }

    cout << ans+PSP.build() << '\n';
}