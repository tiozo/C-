#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const int maxDP = 40; /// 30
int n, m; 
map<ll, vector<ll>> mp;
ll a[N], dp[maxDP];

ll calc_team(ll val) {
    ll res = 0;

    /// first case
    res = ((a[n] - val + 1) % (m - 1) == 0)
        + (a[n] - val + 1) / (m - 1);
    if (val >= a[1]) {
        res += (abs(val - 1 - a[1]) % (m - 1) == 0)
                + abs(val - 1 - a[1]) / (m - 1); 
    }

    /// second case
    ll tmp = 0;
    tmp = ((a[n] - val) % (m - 1) == 0)
            + (a[n] - val) / (m - 1);
    if (val >= a[1]) {
        tmp =  ((val - a[1]) % (m - 1) == 0) 
                + ((val - a[1]) / (m - 1));
    }
    return min(res, tmp);
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    /*int k = 1;
    ll L = a[1], R = a[n], prev = 0;
    while (L < R) {
        ll mid = L + (R - L) / 2;
        pair<ll, ll> cur = calc(mid);
        if (cur.first > prev) L = mid;
        else R = mid - 1;
        dp[k++] = cur.first;
        mp[dp[k]].push_back(cur.second);
    }
    ll ans = 1e18;
    vector<ll> start;
    for (int i = 1; i <= k; ++i) {
        if (ans > dp[i]) {
            ans = dp[i];
            start = mp[dp[i]];
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < start.size(); ++i) {
        cout << start[i] << ' ';
    }*/
    for (int i = a[1]; i <= a[n]; ++i) {
        auto cur = calc_team(i);
        if (cur <= 1 && m < n) cur = 1e18; 
        cout << cur << '\n';
    }
    return 0;  
}