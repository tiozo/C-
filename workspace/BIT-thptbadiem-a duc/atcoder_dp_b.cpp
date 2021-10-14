#include<bits/stdc++.h>
using namespace std;

const int NK = 1e6+1;
int dp[NK];

int main() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for (auto &e:a) cin >> e;
    memset(dp,0x3f,sizeof dp);
    dp[0] = 0;
    for (int i=0;i<n;++i) {
        for (int j=1;j<=k;++j) {
            if (i+j<n) dp[i+j] = min(dp[i+j], dp[i] + abs(a[i]-a[j+i]));
        }
    }
    cout << dp[n-1];
    return 0;
}