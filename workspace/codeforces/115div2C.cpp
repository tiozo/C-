#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        ll sum = 0;
        for (int i=1;i<=n;++i) {
            cin >> a[i]; 
            sum += a[i];
        }
        ll req = 2 * sum / n;
        map<ll,ll> cnt;
        ll ans = 0;
        if ((sum - req) * n != sum * (n - 2)) {
            cout << "0\n";
            continue;
        }
        for (int i=1;i<=n;++i) {
            ans += 1ll * cnt[req - a[i]];
            cnt[a[i]]++;
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
    let do some math change
    we can see the problems as
    sum/n = (sum - a[i] - a[j])/(n - 2)
    <=> sum * (n - 2) = sum * n - a[i] * n - a[j] * n
    a[i] + a[j] = 2 * sum / n (1)
    its mean that required sum remove element is 2 * sum / n
    so just need to store all the all the difference of required with any a[i];
    and at a[i] to the expected difference of req and some a[j] with j>i
    this can easily be solve by using map.
*/