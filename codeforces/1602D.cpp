#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 100;
int a[maxn], b[maxn];

struct DSU {
    int par[maxn];
    DSU() {};
    void pre(int size) {
        for (int i=1;i<=size+1;++i) {
            par[i] = i;
        }
    };
    int find(int u) {
        return u==par[u] ? u : par[u] = find(par[u]);
    }
    void join(int u,int v) {
        par[find(u)] = find(v); 
    }
}dsu;

queue<int> q; 
int f[maxn], pre[maxn], n;
int ans,ap;

void BFS() {
    dsu.pre(n); q.push(1); dsu.join(1,2);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        //cout << u << '\n';
        if (u-b[u]+a[u-b[u]] > n) {
            ans = f[u] + 1; ap = u; pre[n+1] = u; return; 
        }
        for (int i=dsu.find(u-b[u]);i<=u-b[u]+a[u-b[u]];i=dsu.find(i)) {
            q.push(i); pre[i] = u; f[i] = f[u] + 1; dsu.join(i,i+1);
        }
    }
}

void trace(int u) {
    if (u==1) return;
    if (pre[u]) trace(pre[u]);
    cout << n - u + 1 << ' ';
}

int main() {
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=n;++i) {
        cin >> b[i];
    }
    reverse(a+1,a+1+n);
    reverse(b+1,b+1+n);
    ans = -1; BFS();
    //cout << "-1";
    if (ans==-1) cout << "-1\n";
    else {
        cout << ans << '\n';
        trace(n+1); cout << '\n';
    }
    return 0;
}

/*  0
3 2 
2 2 1
1 0 

*/