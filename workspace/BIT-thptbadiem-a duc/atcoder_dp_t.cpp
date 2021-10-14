#include<bits/stdc++.h>
using namespace std;

const int maxn = 3000;
const int mod = 1e9+7;
int dp[maxn+1],dq[maxn+1];

int main() {
    int n; cin >> n;
    string s; cin >> s;
    dp[1] = 1;
    for (int i=1;i<n;++i) {
        for (int j=1;j<=i+1;++j) {
            dp[j] = (dp[j] + dp[j-1])%mod;
        }
        for (int j=1;j<=i+1;++j) {
            if (s[i-1]=='>') {
                dq[j] = (dp[i] - dp[j-1] + mod) % mod;
            } else {
                dq[j] = dp[j-1];
            }
        }
        swap(dp,dq);
    }
    int ans = 0;
    for (int i=1;i<=n;++i) {
        ans = (ans+dp[i])%mod;
    }
    cout << ans << '\n';
    return 0;
}