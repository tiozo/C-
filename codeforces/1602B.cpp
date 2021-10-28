#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2100;
int f[maxn][maxn], a[maxn];
map<int,int> mp; 

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> a[i], mp[a[i]]++;
        for (int i=1;i<=n;++i) f[i][0] = a[i];
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=n;++j) a[j] = mp[a[j]], f[j][i] = a[j];
            for (int j=1;j<=n;++j) mp[j] = 0;
            for (int j=1;j<=n;++j) mp[a[j]]++;
        }
        int q; cin >> q;
        while (q--) {
            int x,k; cin >> x >> k;
            k = min(k,n);
            //--x; --k;
            cout << f[x][k] << '\n';
        }
        for (int i=1;i<=n;++i) mp[i] = 0;
    }
    return 0;
}