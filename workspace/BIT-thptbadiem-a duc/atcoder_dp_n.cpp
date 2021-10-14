#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 410;
int a[maxn];
ll dp[maxn][maxn],p[maxn];

auto query (int l,int r) {
    return p[r] - (l==0 ? 0 : p[l-1]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    p[0] = 0;
    for (int i=1;i<=n;++i) {
        p[i] = p[i-1] + a[i];
    }
    memset(dp,0x3f,sizeof dp);
    for (int i=1;i+1<=n;++i) dp[i][i+1] = a[i] + a[i+1];
    for (int i=1;i<=n;++i) dp[i][i] = 0;
    for (int i=n;i>=1;--i) {
        for (int j=i+2;j<=n;++j) {
            ll best = 1e18;
            for (int k=i;k<j;++k) {
                best = min(best,dp[i][k]+dp[k+1][j]);
            }
            dp[i][j] = query(i,j) + best;
        }
    }
    cout << dp[1][n];
    return 0;
}