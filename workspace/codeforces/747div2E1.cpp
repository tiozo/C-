#include<bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int powmod(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (1ll * res * a) % mod; 
        a = (1ll * a*a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int32_t main() {
    int k; cin >> k;
    int res = (1ll * 6 * powmod(4,(1ll<<k)-2))  % mod;
    cout << res << '\n';
    return 0;
}