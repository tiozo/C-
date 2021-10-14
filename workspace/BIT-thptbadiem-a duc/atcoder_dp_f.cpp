#include<bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int g[maxn][maxn],dp[maxn][maxn];
char s[maxn],t[maxn];

int main() {
    cin >> s >> t;
    int n = strlen(s);
    int m = strlen(t);
    for (int i=0;i<=n;++i) {
        for (int j=0;j<=m;++j) {
            if (!i || !j) dp[i][j] = 0;
            if (s[i-1]==t[j-1]) g[i][j] = g[i-1][j-1] + 1;
            else g[i][j] = max(g[i-1][j],g[i][j-1]);
        }
    }
    string res = "";
    while (n&&m) {
        if (s[n-1]==t[m-1]) {
            res += s[n-1];
            n--;
            m--;
        } else if (g[n-1][m]>g[n][m-1]) {
            n--;
        } else m--;
    }
    reverse(res.begin(),res.end());
    cout << res;
    return 0;
}