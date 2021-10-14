#include<bits/stdc++.h>
using namespace std;

const int maxn = 3010;
long long a[maxn],dp[maxn][maxn];

int main() {
    int n; cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=n;++i) dp[i][i] = a[i];
    for (int i=n;i>=1;--i) {
        for (int j=i+1;j<=n;++j) {
            dp[i][j] = max(a[i]-dp[i+1][j],a[j] - dp[i][j-1]);
        }
    }
    cout << dp[1][n];
    return 0;
}

/*
4
10 80 90 30

taro : 10 
jiro : 80
taro : 90

*/