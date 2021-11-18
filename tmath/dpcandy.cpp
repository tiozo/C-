#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 2e5 + 10;
ll a[maxn], prefix[maxn], suffix[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(prefix, 0, sizeof prefix);
    memset(suffix, 0, sizeof suffix);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
        //cout << a[i - 1] << ' ';
    }
    for (int i = n; i >= 1; --i) {
        suffix[i] = suffix[i + 1] + a[i - 1];
    }
    ll ans = 2e9;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, abs(suffix[i + 1] - prefix[i]));
        //cout << suffix[i + 1] << ' ' << prefix[i]  << '\n';
    }
    cout << ans << '\n';
    return 0;
}

/*
    O(n^2) naive ways is just to calc all the possible |prefix[i] - prefix[j]|
    take the min out
    O(n log n) should work out with BIT or IT 
    hold on what the fuc am i doing, this just ask for the k 
    lol
*/