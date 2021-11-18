#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void read() {}

template<typename First, typename ...Rest>
void read(First& first, Rest&... rest) {
    cin >> first;
    read(rest...);
}

template<class X,class Y>
void add(X &x,Y y) {
    x = (x + y) % mod;
}

template<class X,class Y>
void minus(X &x,Y y) {
    x = (x - y + mod) % mod;
}

template<class X,class Y>
void multiply(X &x,Y y) {
    x = (1ll * x * y) % mod;
}

template<class X,class Y>
void maximize(X &x,Y y) {
    X esp = 1e-9;
    if (x + esp < y) x = y;
}

template<class X,class Y>
void minimize(X &x,Y y) {
    X esp = 1e-9;
    if (x > y + esp) x = y;
}

struct dsu {
    vector<int> par;
    dsu(int n = 0) {
        par.assign(n + 10,-1);
    }
    int find(int u) {
        return par[u] < 0 ? u : par[u] = find(par[u]);
    }
    bool join(int u,int v) {
        u = find(u), v = find(v);
        if (u==v) return false;
        if (par[u] > par[v]) swap(u,v);
        par[u] += par[v], par[v] = u;
    }
};

/// ANNOUNCE: end of template

struct Line {
    ll k, m, p;
    bool operator < (const Line &o) const {
        return k < o.k;
    }
    bool operator < (ll x) const {
        return p < x;
    }
    ll get(ll x) {
        return k * x + m;
    }
};

const ll inf = LLONG_MAX;
int n; 
ll c;
deque<Line> hull;
vectro<ll> h, dp;

void solve() {
    read(n,C);
    for (int i=1;i<=n;++i) {
        read(h[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}