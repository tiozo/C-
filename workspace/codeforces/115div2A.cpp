#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
const pair<int,int> moveset[8] = {{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
bool vis[2][maxn];
int n, a[2][maxn];

bool inbound(int u,int v) {
    return (u>=0 && v>=0 && u<2 && v<n);
}

void dfs(int u,int v) {
    vis[u][v] = 1;
    for (int i=0;i<8;++i) {
        int x = u + moveset[i].first, y = v + moveset[i].second;
        //cout << (inbound(x,y) && a[x][y] == 0 && !vis[x][y]) << '\n';
        if (inbound(x,y) && a[x][y] == 0 && !vis[x][y]) {
            dfs(x,y);
        }
    }
}

void solve() {
    memset(vis,0,sizeof vis);
    cin >> n;
    for (int i=0;i<2;++i) {
        string s; cin >> s;
        for (int j=0;j<n;++j) {
            if (s[j]=='0') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    dfs(0,0);
    if (vis[1][n-1]) {
        cout << "YES\n";
    } else cout << "NO\n";
}
 
int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}

/*
000
000 
000

-1 -1
-1 1
-1 1
1 1
0 -1
0 1
1 0
-1 0
*/
