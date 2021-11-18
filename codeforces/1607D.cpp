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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    string s; cin >> s;
    bool flag = true;
    for (int i=0;i<n;++i) {
        if ((s[i]=='R' && a[i] >= n)) {
            flag = false; break;
        }
    }
    if (flag) {
        int allfalse = 0;
        for (int i=0;i<n;++i) {
            if (s[i]=='B' && a[i]<=1) {
                ++allfalse;
            }
        }
        cout << "IN" << '\n';
        if (allfalse>n) cout << "YES\n";
        else cout << "NO\n";
    } else cout << "NO\n";
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}