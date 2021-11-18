#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 36 + 100;
ll a[maxn];

int main() {
    int n; cin >> n;
    ll x; cin >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        for (ll bits = 0; bits < (1ll<<n); ++bits) {
            ll need_val = k * x;
            ll sum = 0;
            for (int i = 1; i <= n; ++i) {
                int cur_bit = i - 1;
                if ((bits>>cur_bit)&1) {
                    sum += a[i];
                    //cout << a[i] << ' ';
                }
            }
            //cout << sum << '\n';
            if (sum == need_val) ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
    4 + 4 + 6 + 6
    20 / 4 = 5 == x
    1
    4 + 6 + 4
    14 / 3 != 5
    4 4 
    != 5
    4 6 == 5
    6 4 == 5

*/