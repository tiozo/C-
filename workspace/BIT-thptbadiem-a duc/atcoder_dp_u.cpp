#include<bits/stdc++.h>
using namespace std;

long long taro = 0;
int a[17][17];
long long cost[(1<<16)+1],dp[(1<<16)+1];

int main() {
    int n; cin >> n;
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<(1<<n);++i) {
        for (int j=0;j<n;++j) {
            for (int k=j+1;k<n;++k) {
                if (((i>>j)&1) && ((i>>k)&1)) {
                    cost[i] += a[j][k];
                }
            }
        }
    }
    for (int i = 0; i < (1<<n); ++i) {
        int j = ((1<<n)-1)^i;
        for (int k = j; k; k = (k-1) &j) {
            dp[i^k] = max(dp[i^k],cost[k]+dp[i]);
        }
    }
    taro = dp[(1<<n)-1];
    cout << taro << '\n';
    return 0;
}
