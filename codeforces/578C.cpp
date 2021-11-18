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

const double eps = 1e-9;

double msc(vector<double> &a) {
    double mx = 0, now = 0;
    for (int i = 0; i < a.size(); ++i) {
        now += a[i];
        if (now > mx + eps) mx = now;
        if (now + eps < 0) now = 0;
    }
    return mx;
}

void calc(double m, vector<double> &a, double &v1, double &v2) {
    auto b = vector<double>(a.size());
    for (int i = 0; i < a.size(); ++i) b[i] = a[i] - m;
    v1 = msc(b);
    for (int i = 0; i < a.size(); ++i) b[i] *= -1;
    v2 = msc(b);
    //return v1;
}


void solve() {
    int n; cin >> n;
    vector<double> a(n);
    for (double i : a) cin >> i;
    double L = -1e9, R = 1e9;
    for (int i = 0; i < 100; ++i) {
        double mid = (L + (R - L) / 2), prev, cur;
        calc(mid, a, cur, prev);
        cout << cur << ' ' << prev << '\n';
        if (cur > prev) L = mid;
        else R = mid;
    }
    double mid = (L + (R - L) / 2), prev, cur;
    calc(mid, a, cur, prev);
    cout << double(max(cur, prev));
}

int main() {
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}