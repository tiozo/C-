#include<bits/stdc++.h>
using namespace std;

const int maxn = 21;
const int mod = 1e9+7;
bool a[maxn][maxn];
int dp[1<<maxn];

int main() {
    int n; cin >> n;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for (int s=0;s<(1<<n);++s) {
        int pair_num = __builtin_popcount(s);
        for (int w=0;w<n;++w) {
            if (((s>>w)&1) || !a[pair_num][w])
				continue;
            dp[s|(1<<w)] = (dp[s|(1<<w)]+dp[s])%mod;
        }
    }
    cout << dp[(1<<n)-1];
    return 0;
}