#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1e18;
set<ll> s;
map<ll,ll> F;

ll calc(ll n) {
    if (F.count(n)) return F[n];
    ll k = n/2;
    if (n%2==0) {
        F[n] = (calc(k)*calc(k)+calc(k-1)*calc(k-1))%mod;
        s.insert(F[n]);
        return F[n];
    } else {
        F[n] = (calc(k)*calc(k+1)+calc(k)*calc(k-1))%mod;
        s.insert(F[n]);
        return F[n];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    F[0] = F[1] = 1; s.insert(1);
    calc(1e7);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        if (s.count(n%mod)>=1) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
