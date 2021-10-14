#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,k; cin >> n >> k;
        long long ans = 0, p = 1;
        for (int bits = 0; bits < 31; ++bits) {
            if ((k>>bits)&1) {
                ans = (ans+p)%mod;
            }
            p = (p*n)%mod;
        }
        cout << ans << '\n';
    }
    return 0;
}
