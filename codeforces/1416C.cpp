#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 3e5 * 31 + 10;
int child[MAX][2];
int nxt = 1;
int cnt[MAX];
ll inv[32][2];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        int node = 0;
        for (int pos = 29; pos >= 0; --pos) {
            bool bit = bool((x >> pos) & 1);
            inv[pos][bit] += cnt[child[node][!bit]];
            if (child[node][bit] == 0) {
                child[node][bit] = nxt++;
            }
            node = child[node][bit];
            cnt[node]++;
            //cout << inv[pos][bit] << '\n';
        }
    }
    ll ans = 0, x = 0;
    for (int pos = 0; pos < 30; ++pos) {
        if (inv[pos][0] > inv[pos][1]) {
            x ^= (1 << pos);
        }
        ans += min(inv[pos][0], inv[pos][1]);
    }
    cout << ans << ' ' << x << '\n';
    return 0;
}

/*
    trie problem
*/