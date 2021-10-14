#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxque = 1000*1000;
const int moveset[5] = {0, 1, 0, -1, 0};
int n,m,front=0,rear=0;
int a[maxn+1][maxn+1];
int d[maxn+1][maxn+1];
vector<int> row[maxn+1],col[maxn+1];
pair<int,int> que[maxque+1];

bool inbound(int u,int v) {
    return (u>=1 && v>=1 && u<=n && v<=m);
}

inline void push(int u,int v) {
    que[rear++] = {u,v};
}

void pop() {
    ++front;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    /* #ifndef TioZo 
        freopen("output.out","w",stdout);
    #endif */
    cin >> n >> m;
    //cout << front << ' ' << rear << '\n';
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cin >> a[i][j];
            if (a[i][j]) {
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }
    memset(d,-1,sizeof d);
    d[1][1] = 0;
    push(1,1);
    while (front<=rear) {
        int u = que[front].first, v = que[front].second; pop();
        //cout << u << ' ' << v << '\n';
        //cout << u.first << ' ' << u.second << '\n';
        if (u == n && v == m) {
            cout << d[u][v] << '\n';
            return 0;
        }
        for (int i=0;i<4;++i) {
            int x = u + moveset[i], y = v + moveset[i+1];
            if (!inbound(x,y)) continue;
            if (d[x][y]!=-1) continue;
            d[x][y] = d[u][v] + 1;
            //cout << "in: " << x << ' ' << y << '\n';
            push(x,y);
        }
        if (a[u][v]==1) {
            int f1 = lower_bound(row[u].begin(),row[u].end(),v) - row[u].begin() - 1;
            int s1 = upper_bound(row[u].begin(),row[u].end(),v) - row[u].begin();

            if (s1==row[u].size()) s1 = m;
            else s1 = row[u][s1];
            if (f1<0) f1 = 1;
            else f1 = row[u][f1];

            for (int i = f1; i <= s1; ++i) {
                if (d[u][i]==-1) {
                    d[u][i] = d[u][v] + 1;
                    push(u,i);
                }
            }

            f1 = lower_bound(col[v].begin(),col[v].end(),u) - col[v].begin() - 1;
            s1 = upper_bound(col[v].begin(),col[v].end(),u) - col[v].begin();

            if (s1==col[v].size()) s1 = n;
            else s1 = col[v][s1];
            if (f1<0) f1 = 1;
            else f1 = col[v][f1];

            for (int i = f1; i <= s1; ++i) {
                if (d[i][v]==-1) {
                    d[i][v] = d[u][v] + 1;
                    push(i,v);
                }
            }
        }
    } 
    return 0;
}