#include<bits/stdc++.h>
using namespace std;

struct edge {
    int u,v,c;
};

const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int n, m, u, v, c, A, B, x, y;
int a[maxn], b[maxn], dd[maxm];
edge e[maxm];

struct dsu {
    int bac[maxn], par[maxn];
    dsu() {};
    dsu(int size) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
            bac[i] = 0;
        }
    };
    void reset(int size) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
            bac[i] = 0;
        }
    }
    int find(int u ){
        return u==par[u] ? par[u] : u = find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u);
        v = find(v);
        if (u==v) return false;
        if (bac[u] == bac[v]) bac[u]++;
        if (bac[u] > bac[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};

int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        dsu set1(n), set2(n);
        for (int i=1;i<n;++i) cin >> a[i];
        for (int i=1;i<n;++i) cin >> b[i];
        for (int i=1;i<=m;++i) 
            cin >> e[i].u >> e[i].v >> e[i].c;
        A = B = 0;
        for (int i=1;i<=m;++i) {
            dd[i] = 0;
        }
        for (int i=1;i<=m;++i) {
            if (e[i].c==1) A += set1.join(e[i].u,e[i].v);
            else if (e[i].c==2) B += set2.join(e[i].u,e[i].v);
        }
        int sum = 2e9 + 10;
        for (int i=max(0,n-B-1);i<=min(A,n-1);++i) {
            if (sum > a[i] + b[n-i-1]) {
                sum = a[i] + b[n-i-1];
                x = i;
            }
        }
        y = n-x-1;
        for (int i=1;i<=m;++i) dd[i] = set2.join(e[i].u,e[i].v);
        dsu set3(n);
        int cnt = 0;
        for (int i=1;i<=m;++i) {
            if (dd[i]) {
                cnt += set3.join(e[i].u,e[i].v);
            }
        }
        for (int i=1;i<=m && cnt < x;++i) {
            if (e[i].c==1 && !dd[i]) {
                cnt += (dd[i] = set3.join(e[i].u,e[i].v));
            }
        }
        for (int i=1;i<=m;++i) {
            if (e[i].c==2) dd[i] = set3.join(e[i].u,e[i].v);
        }
        for (int i=1;i<=m;++i) {
            if (dd[i]) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}