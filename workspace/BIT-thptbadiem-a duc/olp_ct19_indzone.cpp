#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;
map<ll,ll> F;

ll calc(ll n) {
    if (F.count(n)) return F[n];
    ll k = n/2;
    if (n%2==0) {
        return F[n] = (calc(k)*calc(k)+calc(k-1)*calc(k-1))%mod;
    } else {
        return F[n] = (calc(k)*calc(k+1)+calc(k)*calc(k-1))%mod;
    }
}

int main() {
    F[0] = F[1] = 1;
    ll n;
    cin >> n;
    cout << calc(n)*calc(n+1);
    return 0;
}