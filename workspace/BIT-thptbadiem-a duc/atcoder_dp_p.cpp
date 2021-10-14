#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7, maxn = 1e5+1;
vector<int> a[maxn];
long long dp[maxn][2];

void dfs(int u,int prev) {
    dp[u][0] = dp[u][1] = 1;
    for (auto v:a[u]) if (v!=prev) {
        dfs(v,u);
        dp[u][0] = (dp[u][0] * dp[v][1])%mod;
        dp[u][1] = ((ll)dp[u][1] * ((dp[v][0]+dp[v][1])%mod))%mod;
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n-1; ++i) {
        int u,v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    } 
    dfs(1,1);
    int res = (dp[1][0]+dp[1][1])%mod;
    cout << res << '\n';
    return 0;
}