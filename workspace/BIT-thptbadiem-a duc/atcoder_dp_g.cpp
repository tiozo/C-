#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
vector<int> adj[maxn];
bool vis[maxn];
int d[maxn] = {0};

int dfs(int u) {
    if (d[u]) return d[u];
    //vis[u] = 1;
    for (auto &v:adj[u]) {
        d[v] = dfs(v);
        d[u] = max(d[v]+1,d[u]);
    }
    return d[u];
}

int main() {
    int n,m; cin >> n >> m;
    for (int i=1;i<=m;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i=1;i<=n;++i) 
        dfs(i);
    int res = 0;
    for (int i=1;i<=n;++i) {
        res = max(res,d[i]);
    }
    cout << res << '\n';
    return 0;
}