#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 10;
const int K = 55;
int n, m, k, cnt;
int s[N], t[N];
char a[N][N];
bool leaf[N];
ll dp[N][K];
vector<int> adj[N];

int grid_c(int i, int j) {
    return (j == m - 1 ? 0 : (1 + x * (m - 1) + y));
}

void dfs(int u, int prev, bool in_path) {
    s[u] = cnt;
    if (leaf[u]) cnt++;
    for (int v: adj[u]) {
        if (v != prev) {
            dfs(v, u, in_path);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    if ((n * (m - 1) < k)) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m - 1; ++j) {
            int pos = grid_c(i, j);
            if (j == 0) leaf[pos] = true;
            char c = a[i][j];
            if (c == 'R') adj[grid_c(i, j + 1)].push_back(pos);
            if (c == 'L') adj[(grid_c(i, j - 1))].push_back(pos);
            if (c == 'U') adj[grid_c(i + 1, j)].push_back(pos);
            if (c == 'D') adj[grid_c(i - 1, j)].push_back(pos);
        }
    }
    return 0;
}

/*


*/