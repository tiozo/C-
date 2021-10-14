#include<bits/stdc++.h>
using namespace std;
#define int long long
using ld = long double;
int solve(ld h,ld k,vector<ld> &x,vector<ld> &y,int n) {
    int res = 0;
    for (int j=0;j<n;++j) {
        ld dx = h-x[j];
        ld dy = k-y[j];
        if (dx==0 & dy==0) continue;
        else if ((dx==0&&dy!=0)||(dx!=0&&dy==0)) res++;
        else if (abs(dx)==abs(dy)) res++;
        else res+=2;
    } 
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n,ans = INT_MAX; cin >> n;
        vector<ld> x(n),y(n); ld h,k;
        for (auto &e:x) cin >> e;
        for (auto &e:y) cin >> e;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                if (i!=j) {
                    h=x[i],k=y[j];
                    ans = min(ans,solve(h,k,x,y,n));
                    ld c1 = x[i]+y[i];
                    ld c2 = x[j]-y[j];
                    h = (c1+c2)/2, k = (c1-c2)/2;
                    ans = min(ans,solve(h,k,x,y,n));
                    c1 = x[i] + y[i];
                    k = y[j]; h = c1-k;
                    ans = min(ans,solve(h,k,x,y,n));
                    c2 = x[i] - y[i];
                    k = y[j]; h = c2+k;
                    ans = min(ans,solve(h,k,x,y,n));
                }
            }
        }  
        cout << ans << '\n';
    }
    return 0;
}