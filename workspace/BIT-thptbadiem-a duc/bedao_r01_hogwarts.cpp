#include<bits/stdc++.h>
using namespace std;

class uv {
public: 
    int u,v,z;
};

bool operator < (uv &a,uv &b) {
    return a.z < b.z;
}

struct dsu {
    vector<int> par,rank;
    dsu (int size): par(size+1), rank(size+1) {
        for (int i=1;i<=size;++i) {
            par[i] = i;
        }
    }
    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u);
        v = find(v);
        if (u==v) return false;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] > rank[v]) par[v] = u;
        else par[u] = v;
        return true;
    }
};

int main() {
    int n,m,q; cin >> n >> m >> q;
    vector<int> w(n+1);
    for (int i=1;i<=n;++i) {
        cin >> w[i];
    }
    dsu sett(n+1);
    for (int i=1;i<=m;++i) {
        int u,v; cin >> u >> v;
        sett.join(u,v);
    }

    return 0;
}