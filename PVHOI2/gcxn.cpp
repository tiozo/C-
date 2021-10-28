#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define SQR(x) (1ll*(x)*(x))

const int maxn = 3e5 + 300;
const int mod = 998244353;
vector<int> adj[maxn];

inline void minimize(int &u,int v) {
    if (u > v) u = v;
}

struct dsu {
    int par[maxn];
    dsu(int size = 0) {
        for (int i=0;i<=size;++i) {
            par[i] = -1;
        }
    };
    int find(int u) {
        return par[u] < 0 ? u : par[u] = find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u), v = find(v);
        if (u==v) return false;
        if (par[u] > par[v]) swap(u,v);
        par[u] += par[v];
        par[v] = u;
        return true;
    }
    int getSize(int u) {
        return -par[find(u)];
    }
};  

struct cities {
    int u,v;
    bool block;
    cities(int _u=0,int _v=0) {
        u = _u; v = _v;
        block = false;
    };
    int other(int x) const {
        return u ^ v ^ x;
    }
} edges[maxn];

int n,m;
int low[maxn], num[maxn], timerr = 0;
ll resNode[maxn], resEdge[maxn];
int treeSize[maxn], compSize[maxn];
int numComp, numJoint, numBrigde;

void dfs(int u) {
    low[u] = n + 1;
    num[u] = ++timerr;
    treeSize[u] = 1;

    int sum = 0;
    ll sumSqr = 0;
    for (auto &e:adj[u]) if (!edges[e].block) {
        edges[e].block = true;
        int v = edges[e].other(u);
        if (num[v]==0) {
            dfs(v);
            minimize(low[u],low[v]);
            treeSize[u] += treeSize[v];
            if (low[v] > num[u]) {
                resEdge[e] += 1ll * treeSize[v] * (compSize[v] - treeSize[v]);
                resEdge[e] %= mod;
                //cout << resEdge[e] << '\n';
            }
            if (low[v] >= num[u]) {
                sum += treeSize[v];
                sumSqr += SQR(treeSize[v]);
            }
        } else minimize(low[u],num[v]);
    } 

    sumSqr += SQR(compSize[u] - 1 - sum);
    sum = compSize[u] - 1;
    resNode[u] += (SQR(sum) - sumSqr) / 2;
    resNode[u] %= mod;
    //cout << resNode[u] << '\n';
}

void process() {
    dsu sett(n);
    for (int i=1;i<=m;++i) sett.join(edges[i].u,edges[i].v);
    
    ll Sumsqr = 0;
    for (int i=1;i<=n;++i) {
        if (sett.find(i)==i) {
            Sumsqr += SQR(sett.getSize(i));
        }
    }
    
    for (int i=1;i<=n;++i) {
        compSize[i] = sett.getSize(i);
    }
    for (int i=1;i<=n;++i) {
        resNode[i] = (SQR(n) - Sumsqr)/2 - (n-compSize[i]);
        resNode[i] %= mod;
    }
    for (int i=1;i<=m;++i) {
        resEdge[i] = (SQR(n) - Sumsqr)/2;
        resEdge[i] %= mod;
    }

    for (int i=1;i<=n;++i) {
        if (num[i]==0) {
            numComp++;
            dfs(i);
        }
    }

    for (int i=1;i<=n;++i) {
        cout << (resNode[i]%mod) << ' ';
    } cout << '\n';
    for (int i=1;i<=m;++i) {
        cout << (resEdge[i]%mod) << ' ';
    } cout << '\n';
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i=1;i<=n;++i) {
            adj[i].clear();
        }
        for (int i=1;i<=m;++i) {
            int u,v; cin >> u >> v;
            edges[i] = cities(u,v);
            adj[u].push_back(i);
            adj[v].push_back(i);
        }
        process();
    }
    return 0;
}