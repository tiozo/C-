#include<bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a,int b) {
    if (!b) return a;
    return gcd(b,a%b);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,ans = 0; cin >> n;
    if (n==1) {
        int x; cin >> x;
        cout << (int)1e9 << '\n';
        return 0;
    }
    vector<int> a(n);
    for (auto &e:a) {
        cin >> e;
    }
    vector<int> prefix(n),suffix(n);
    prefix[0] = a[0];
    for (int i=1;i<n;++i) {
        prefix[i] = gcd(prefix[i-1],a[i]);
        //cout << prefix[i] << ' ';
    }
    ans = prefix[n-2];
    suffix[n-1] = a[n-1];
    for (int i=n-2;i>=0;--i) {
        suffix[i] = gcd(suffix[i+1],a[i]);
        //cout << suffix[i] << ' ';
    }
    ans = max(ans,suffix[1]);
    for (int i=1;i<n-1;++i) {
        ans = max(gcd(prefix[i-1],suffix[i+1]),ans);
    }
    cout << ans << '\n';
    return 0;
}
