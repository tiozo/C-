#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[42];
int cnt[2<<20 + 1], vis[2<<20 + 1];

int main() {
    int tc; cin >> tc;
    int tmp = 0;
    while (tc--) {
        int n; cin >> n;
        for (int i=0;i<n;++i) cin >> a[i], a[i] += 1e6;
        int g;
        for (g=2e6 + 1;g>0;--g) {
            int mx = 0; tmp++;
            for (int i=0;i<n;++i) {
                int x = a[i] % g;
                if (vis[x]<tmp) vis[x] = tmp, cnt[x]=0;
                if (mx < ++cnt[x]) mx = cnt[x];
            }
            if (mx*2>=n) break;
        }
        if (g==2e6 + 1) g = -1;
        cout << g << '\n';
        /// random bull shit go
    }
    return 0;
}

/// source: kotatsugame