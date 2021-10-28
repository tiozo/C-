#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
const int mod = 1e9+7;
long long f[maxn];

int main() {
    f[1] = 1;
    for (int i=2;i<=1e5;++i) {
        f[i] = ((i<<1)-1ll)*f[i-1]%mod*(i<<1)%mod;
    }
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}