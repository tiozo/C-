#include<bits/stdc++.h>
using namespace std;

struct uvc {
    int u, w;
    bool used = false;
    uvc(int u = 0, int w = 0) {
        this -> u = u;
        this -> w = w;
    }
};

const int N = 1e5 + 100;
int n, m, s, res = 0;
vector<uvc> adj[N];
vector<int> path;

void dfs(int u, int start_node) {
    for (auto &e : adj[u]) {
        if (e.u == start_node && e.used == false) {
            cout << "u: "<< u << ' ' << e.u << '\n';
            int minn = 1e9, maxx = -1e9;
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i] << ' ';
                minn = min(minn, path[i]);
                maxx = max(maxx, path[i]);
            }
            cout << '\n';
            s = minn + maxx;
            res = max(res ,s);
        }
        if (!e.used) {
            e.used = true;
            path.push_back(e.w);
            dfs(e.u, start_node);
            e.used = false;
            adj[e.u][u].used = false;
            path.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back(uvc(v, w));
        adj[v].push_back(uvc(u, w));
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, i);
    }
    cout << res << '\n';
    return 0;
}