#include<bits/stdc++.h>

using namespace std;
using ld = double;

const int maxn = 3000;
int n;
ld a[maxn];
ld dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mid = n/2+1;
    for (int i=0;i<=n;++i) {
        dp[i][0] = 1;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=mid;++j) {
            dp[i][j] = dp[i-1][j-1]*a[i-1] + dp[i-1][j]*(1-a[i-1]);
        }
    }
    cout << fixed << setprecision(10) << dp[n][mid];
    return 0;
}