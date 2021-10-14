#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()

const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    long long f=1,p2=1;
    for (int i=2;i<=n;++i) {
        f=f*i%mod;
        p2=p2*2%mod;
    }
    cout << ((f-p2+mod)%mod) << '\n';
}

int main() {
    solve();
    return 0;
}