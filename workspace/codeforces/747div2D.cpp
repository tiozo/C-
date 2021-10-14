#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
vector<vector<pair<int,int>>> adj;
int c[2];
int color[maxn];
bool ok;

void dfs(int u) {
    c[color[u]]++;
    for (auto &v:adj[u]) {
        if (color[v.first]==-1) {
            color[v.first] = color[u] ^ v.second;
            dfs(v.first);
        } else if (color[v.first] != (color[u] ^ v.second)) {
            ok = false;
        }
    }
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,m; cin >> n >> m;
        adj.assign(n+2,vector<pair<int,int>>());
        for (int i=0;i<=n;++i) {
            color[i] = -1;
        }
        for (int i=1;i<=m;++i) {
            int a,b; string c;
            cin >> a >> b >> c;
            if (c[0] == 'c') {
                adj[a].push_back({b,0});
                adj[b].push_back({a,0});
            } else {
                adj[a].push_back({b,1});
                adj[b].push_back({a,1});
            }
        }
        int ans = 0; ok = true;
        for (int i=1;i<=n;++i) {
            if (color[i]==-1) {
                color[i] = 0;
                /// gia su tin vao loi noi cua nguoi thu i
                c[0] = c[1] = 0; 
                dfs(i);
                ans += max(c[0],c[1]);
            }
        }
        if (!ok) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}