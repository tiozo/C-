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

const int N = 1e5 + 100;
ll dp[N];

class SegTree {
private:
    ll tree[4 * N], lazy[4 * N];
    int tree_node;
public:
    #define cur tree[id];
    #define left id<<1
    #define right (id<<1)|1
    void reset(int id, int L, int R) {
        if (L > R) return;
        if (L == R) {
            tree[id] = dp[L];
            return;
        }
        int mid = (L + (R - L) / 2);
        reset(left, L, mid);
        reset(right, mid + 1, R);
        tree[id] = max(tree[left], tree[right]);
    }
    void shift(int id) {
        if (!lazy[id]) return;
        lazy[left] += lazy[id];
        lazy[right] += lazy[id];

        tree[left] += lazy[id];
        tree[right] += lazy[id];
        lazy[id] = 0;
    }
    void update(int id, int L, int R, int u, int v, ll val) {
        if (u > R || L > v) {
            return;
        }
        if (u <= L && R <= v) {
            lazy[id] += val;
            tree[id] += val;
            return;
        }
        shift(id);
        int mid = L + (R - L) / 2;
        update(left, L, mid, u, v, val);
        update(right, mid + 1, R, u, v, val);
        tree[id] = max(tree[left], tree[right]);
    }
    ll get(int id, int L, int R, int u, int v) {
        if (L > v || R < u) {
            return -1e18;
        }
        if (u <= L && R <= v) {
            return tree[id];
        }
        shift(id);
        int mid = (L + (R - L) / 2);
        return (max(get(left, L, mid, u, v)
                    , get(right, mid + 1, R, u, v)));
    }
    void reset(int n) {
        this -> tree_node = n;
        reset(1, 1, tree_node);
    }
    void update(int u, int v, int val) {
        update(1, 1, tree_node, u, v, val);
    }
    ll get(int u, int v) {
        return get(1, 1, tree_node, u, v);
    }
};

SegTree IT;

void precal() {
    dp[0] = 0, dp[1] = 1;
    for (int i = 1; i * 2 + 1 <= N; ++i) {
        dp[i*2] = dp[i];
        dp[i*2 + 1] = dp[i] + dp[i + 1];
        //cout << dp[i * 2] << ' ' << dp[i * 2 + 1] << '\n';
    }
    IT.reset(N);
}

void solve() {
    int n; cin >> n;
    cout << IT.get(1, n) << '\n';
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    precal();
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}