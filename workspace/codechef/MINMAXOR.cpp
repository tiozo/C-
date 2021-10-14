#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int maxn = 3e5;
int fac[maxn];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fac[0] = 1;
    for (int i=1;i<maxn;++i) {
        fac[i] = (i*fac[i-1])%mod;
    }
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        n = (1<<n);
        if (n==2) cout << 2 << '\n';
        else cout << (4*fac[n/2])%mod << "\n";
        for (int i=0;i<n/2;++i) {
            if(i&1) cout << i << " " << i+n/2 << " ";
            else cout << i+n/2 << " " << i << " ";
        }
        cout << '\n';
    }
    return 0;
}