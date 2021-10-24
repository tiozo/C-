#include<bits/stdc++.h>
using namespace std;

const int moveset[4] = {0,1,0,-1};
const int maxn = 1e4 + 100;
const int inf = 1e9 + 7;
int N,M;
bool vis[maxn][maxn];
int dist[maxn][maxn], a[maxn][maxn];

bool inbound(int u,int v) {
    return (u>=1 && v>=1 && u<=N && v<=M);
}

int main() {
    freopen("input.inp","r",stdin);
    cin >> N >> M;
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            cin >> a[i][j];
            dist[i][j] = inf;
            vis[i][j] = false;
        }
    }
    priority_queue<pair<int,int>> d;
    d.push({1,1});
    dist[1][1] = 0;
    //cout << "??";
    while (!d.empty()) {
        int u = d.top().first, v = d.top().second;
        d.pop();
        if (u==N && v==M) {
            cout << dist[u][v] << '\n';
            return 0;
        }
        for (int i=0;i<3;++i) {
            int x = u + moveset[i], y = v + moveset[i+1];
            if (inbound(x,y) && dist[x][y] > dist[u][v] + 1 && a[x][y]==0) {
                d.push({x,y});
                dist[x][y] = dist[u][v] + 1;
                //cout << x << ' ' << y << '\n';  
            }
        }
        //cout << u << ' ' << v << '\n';
    }
    cout << -1 << '\n';
    return 0;
}

/*
6 8
0 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0
0 0 1 0 0 1 1 1
1 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 1 1 0 0
ans = 12
*/