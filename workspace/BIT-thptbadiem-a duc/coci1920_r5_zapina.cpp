#include<bits/stdc++.h>
using namespace std;

const int maxn = 500;
const int mod = 1e9+7;

void add(int &a,int b) {
    if ((a+=b)>=mod) a-=mod;
}

inline int mul(int a, int b) {
    return (long long)a * b % mod;
}

int N,dp[maxn+1][maxn+1][2];
int g[maxn+1][maxn+1];

inline int calc(int flag,int a,int b) {
    if (b>N) {
        if (a!=0) return 0;
        return flag;
    }
    if (a==0) return flag;
    if (dp[a][b][flag]!=-1) return dp[a][b][flag];
    int res = 0;
    for (int i=0;i<=a;++i) {
        add(res, mul(g[a][i], calc(flag | (b == i), a - i, b + 1)));
        //cout << res << '\n';
    }
    return dp[a][b][flag] = res;
}

int main() {
    cin >> N;
    memset(dp,-1,sizeof dp);
    g[0][0] = 1;
    for (int i=1;i<=maxn;++i) {
        for (int j=0;j<=i;++j) {
            g[i][j] = g[i-1][j];
            if (j) add(g[i][j],g[i-1][j-1]);
        }
    }
    cout << calc(0,N,1) << '\n';
    return 0;
}