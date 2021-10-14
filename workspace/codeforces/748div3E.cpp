#include<bits/stdc++.h>
using namespace std;

const int maxn = 4*1e5 + 1;
vector<int> adj[maxn];
int d[maxn],vis[maxn];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,k; cin >> n >> k;\
        queue<int> q;
        for (int i=1;i<=n;++i) {
            vis[i] = d[i] = 0;
            adj[i].clear();
        }
        for (int i=1;i<n;++i) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++d[u];
            ++d[v];
        }
        int res = n;
        for (int i=1;i<=n;++i) {
            if (d[i]<=1) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res--;
            if (vis[u] == k) continue;
            for (auto &v:adj[u]) {
                if (!vis[v]) {
                    d[v]--;
                    if (d[v]<=1) {
                        vis[v] = vis[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}

/*
    this problem is just a matter to find if the verticles with 2 edges if fond, its must be a leaf node, just delete most of it, if the branch we are doing operations on surpass k then we wont care about it
*/