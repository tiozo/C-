#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        long long n; cin >> n;
        vector<long long> a(n);
        for (auto &e:a) cin >> a;
        auto b = a;
        for (long long i=0;i<n;++i) {
            if (a[i]%4==0) {
                b[i] = 2;
            } else if (a[i]%2==0) {
                b[i] = 1;
            } else b[i] = 0;
        }
        auto prefix = b;
        for (long long i=1;i<n;++i) {
            prefix[i] = prefix[i-1] + b[i];
        }
        for (long long i=0;i<n;++i) {
            if (b[i]==0) {
                long long id = upper_bound(prefix.begin(),prefix.end(),prefix[i])-prefix.begin();
                ans += id-i;
                id = lower_bound(prefix.begin(),prefix.end(),prefix[i]+2)-prefix.begin();
                ans += n-id;
            } else if (b[i]==1) {
                id = lower_bound(prefix.begin(),prefix.end(),prefix[i]+1)-prefix.begin();
                ans += n-id;
            } else ans += n-i;
        }
        cout << ans << '\n';
    }
    return 0;
}