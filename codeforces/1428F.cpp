#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void IOS() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

const int MAX = 5e5 + 10;

ll a[MAX];

class SegTree {
private:
    const static int MAXN = 5e5 * 4 + 10;
    ll lazy[MAXN], tree[MAXN];
    ll tree_n;
public:
    #define left (id<<1)
    #define right ((id<<1)|1)
    void shift(int id, int l, int r) {
        lazy[left] += lazy[id];
        lazy[right] += lazy[id];
        int mid = l + (r - l) / 2;
        tree[left] += lazy[id] * (mid - l + 1);
        tree[right] += lazy[id] * (r - (mid + 1) + 1);
        lazy[id] = 0;
    }
    void reset(int id, int l, int r) {
        if (l > r) return;
        if (l == r) {
            lazy[id] = 0;
            tree[id] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        reset(left, l, mid);
        reset(right, mid + 1, r);
        lazy[id] = 0;
        tree[id] = tree[left] + tree[right];
    }
    void reset(int n) {
        this->tree_n = n;
        reset(1, 1, tree_n);
    }
    void update(int id, int l, int r, int u, int v, ll val) {
        if ( l > v || r < u ) return;
        if ( l >= u && r <= v) {
            lazy[id] += val;
            tree[id] += val * (r - l + 1);
            return;
        }
        shift(id, l , r);
        int mid = l + (r - l) / 2;
        update(left, l, mid, u, v ,val);
        update(right, mid + 1, r, u, v, val);
        tree[id] = tree[left] + tree[right];
    }
    void update(int u, int v, ll val) {
        update(1, 1, tree_n, u, v, val);
    }
    ll get(int id, int l, int r, int u, int v) {
        if ( l > v || r < u) return 0;
        if ( l >= u && r <= v ) {
            return tree[id];
        }
        shift(id, l, r);
        int mid = l + (r - l) / 2;
        return (get(left, l, mid, u, v)
                + get(right, mid + 1, r, u, v));
    }
    ll get(int u, int v) {
        return get(1, 1, tree_n, u, v);
    }
};

ll n, streak, cur, res;
string s;
SegTree IT;

int main() {
    IOS();
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        a[i] = n;
    }
    IT.reset(n); res = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            streak = 0;
        } else {
            streak++;
            IT.update(1, streak - 1, -1);
            ll tmp = IT.get(streak, streak);
            IT.update(streak, streak, (i + streak - 1) - tmp);
        }
        res += n * n - IT.get(1,n);
    }
    cout << res << '\n';
    return 0;
}