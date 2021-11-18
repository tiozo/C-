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

const int maxn = 1e6 + 10;
int a[maxn], cnt[maxn];

void solve() {
    int n, k; scanf("%d%d",&n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        //cout << a[i] << '\n';
    }
    int tmp = 0, L = -1, R = -1, j = 0;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; ++i) {
        while (j < n) {
            if (++cnt[a[j]] == 1) tmp++;
            if (tmp > k) {
                if (--cnt[a[j]] == 0) tmp--;
                break;
            }
            j++;
        }
        if (R - L < j - i) {
            L = i, R = j;
        }
        if (--cnt[a[i]] == 0) tmp--;
    }
    cout << L + 1 << ' ' << R << '\n';
}

int main() {
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}