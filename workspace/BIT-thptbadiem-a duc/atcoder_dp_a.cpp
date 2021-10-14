#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int a[maxn+1],dp[maxn+1];

int main() {
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], dp[i] = 1e9;
    if (n==2) {
        cout << abs(a[2]-a[1]) << '\n';
        return 0;
    }
    dp[1] = 0;
    for (int i=1;i<=n;++i) {
        if ((i+1)<=n) dp[i+1] = min(dp[i+1],dp[i]+abs(a[i]-a[i+1]));
        if ((i+2)<=n) dp[i+2] = min(dp[i+2],dp[i]+abs(a[i]-a[i+2]));
    }
    cout << dp[n];
    return 0;
}

/*
4
10 30 40 20

1 -> N
10 
2 + 10
3 + 10

dp[0] = a[0];
dp[1] = a[1];
dp[2] = min(dp[0],dp[1]) + a[2];

*/