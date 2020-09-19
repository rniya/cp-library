#define IGNORE

#define PROBLEM "https://codeforces.com/contest/1361/problem/C"

#include "../../base.hpp"
#include "../../graph/EulerianTrail.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n),b(n);
    for (int i=0;i<n;++i) cin >> a[i] >> b[i];

    vector<int> c;
    for (int i=0;i<n;++i){
        c.emplace_back(a[i]);
        c.emplace_back(b[i]);
    }

    auto calc=[&](int mask){
        EulerianTrail<false> ET(mask+1);
        for (int i=0;i<n;++i){
            a[i]&=mask; b[i]&=mask;
            c[i<<1|0]&=mask; c[i<<1|1]&=mask;
            ET.add_edge(a[i],b[i]);
        }
        return ET.build();
    };

    for (int j=20;j>=0;--j){
        vector<vector<int>> res=calc((1<<j)-1);
        if (res.size()!=1) continue;
        cout << j << '\n';
        vector<int> &v=res[0];
        for (int _=0;_<2;++_){
            vector<int> ans;
            ans.emplace_back(v[0]<<1|_);
            ans.emplace_back(v[0]<<1|(_^1));
            int ok=1;
            for (int i=1;i<n;++i){
                if (c[v[i]<<1|0]==c[ans.back()]){
                    ans.emplace_back(v[i]<<1|0);
                    ans.emplace_back(v[i]<<1|1);
                } else if (c[v[i]<<1|1]==c[ans.back()]){
                    ans.emplace_back(v[i]<<1|1);
                    ans.emplace_back(v[i]<<1|0);
                    continue;
                } else {
                    ok=0; break;
                }
            }
            if (!ok) continue;
            for (int i=0;i<2*n;++i) cout << ans[i]+1 << (i+1==2*n?'\n':' ');
            return;
        }
    }
}