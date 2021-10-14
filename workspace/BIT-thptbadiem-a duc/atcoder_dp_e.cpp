#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
int N,W;
long long dp[maxn];
int w[101],v[101];

void mini(long long &a, const long long &b) {
    if (a>b) a=b;
}

int main() {
    cin >> N >> W;
    for (int i=1;i<=N;++i) cin >> w[i] >> v[i];
    for (int i=0;i<maxn;++i) dp[i] = 1e18;
    dp[0] = 0;
    for (int i=1;i<=N;++i) {
        for (int j=maxn-1;j>=0;--j) {
            if (dp[j]+w[i]<=W) mini(dp[j+v[i]],dp[j]+w[i]);
        }
    }
    for (int i=maxn-1;i>=0;--i) {
        if (dp[i]!=1e18) {
            return cout << i,0;
        }
    }
    return 0;  
}