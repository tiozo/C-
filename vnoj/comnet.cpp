#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1100;
const int K = 5;
int n, k, a, b;
vector<int> adj[N];
int d[N];
ll dp[N][N][K];

void dfs(int u, int prev = -1) {
    dp[u][0][0] = dp[u][0][1] = 1;
    for (int v: adj[u]) {
        if (v != prev) {
            dfs(v, u);
            /// verticies cur for u node, vertiecies cur for v node;
            for (int Ecur = d[u]; Ecur >= 0; --Ecur) {
                for (int Ecur_v = d[v]; Ecur_v >= 0; --Ecur_v) {
                    /// Edges for u node, ..... v node;
                    for (int Vcur = k; Vcur >= 0; -- Vcur) {
                        for (int Vcur_v = 1; Vcur + Vcur_v <= k; ++Vcur_v) {
                            int sumV = Vcur + Vcur_v;
                            int sumE = Ecur + Ecur_v + (Vcur_v < k);
                            dp[u][sumE][sumV] += dp[u][Ecur][Vcur] * dp[v][Ecur_v][Vcur_v];
                        }
                    }
                }
            }
            d[u] += d[v] + 1;
        }
    }
}

int main() {
    cin >> n >> k >> a >> b;
    for (int i = 1; i < n ; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    ll ans = 0;
    for (int i = a; i <= b; ++i) {
        ans += dp[1][i][k];
    }
    cout << ans << '\n';
    return 0;
}

/*
    maxSum is equivalent to N because it's using for 
    counting Node in a tree.
*/