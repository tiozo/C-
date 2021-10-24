#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int color[maxn];
map<int,int> colorkind[maxn];

struct dsu {
    vector<int> par,rak;
    dsu() {};
    dsu(int size): par(size+1), rak(size+1,0) {
        for (int i=0;i<=size;++i) {
            par[i] = -1;
        }
    };
    int find(int u) {
        //cout << u << ' ';
        return par[u] < 0 ? u : par[u]=find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u); v = find(v);
        if (u==v) return false;
        //if (rak[u]==rak[v]) rak[u]++;
        if (colorkind[u].size() < colorkind[v].size()) swap(u,v);
        for (auto &v:colorkind[v]) {
            colorkind[u][v.first] += v.second;
        }
        par[u] += par[v];
        par[v] = u;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i) {
        cin >> color[i];
        color[i] += 1e5;
    }
    for (int i=1;i<=n;++i) {
        ++colorkind[i][color[i]];
    }
    dsu sett(n);
    for (int i=1;i<=q;++i) {
        int type,u,v; cin >> type >> u >> v;
        if (type==1) {
            sett.join(u,v);
        } else {
            u = sett.find(u);
            v += 1e5;
            if (colorkind[u].find(v)!=colorkind[u].end()) {
                cout << colorkind[u][v] << '\n';
            } else cout << 0 << '\n';
        }
    }
    return 0;
}

/*
5 7
-1 1 -1 0 -1
1 1 2
2 1 -1
1 3 5
2 2 1
1 1 3
2 3 -1
2 4 0
*/
