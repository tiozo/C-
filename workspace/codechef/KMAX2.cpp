#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for (auto &a:a) cin >> a;
        int ans= 0;
        int mx = a[0];
        for (int i=0;i<n;++i) {
            mx = max(mx,a[i]);
        }
        for (int i=k-1;i<n;++i) {
            if (a[i]==mx) {
                ans += n-i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

