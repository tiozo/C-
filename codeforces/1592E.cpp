#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn],b[maxn];

map<int,int> mp[2];

int main() {
    int n; cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=19;i>=0;--i) {
        int s = 0;
        mp[0].clear(), mp[1].clear();
        for (int j=1;j<=n;++j) {
            int t = (a[j]>>i)&1;
            s ^= t;
            b[j] = (b[j]<<1)|s;
        }
        mp[0][0] = 0;
        for (int j=1;j<=n;++j) {
            if ((a[j]>>i)&1) {
                auto it = mp[j&1].find(b[j]);
                if (it!=mp[j&1].end()) ans = max(ans,j-it->second);
                else mp[j&1][b[j]] = j;
            } else {
                mp[0].clear(); mp[1].clear();
                mp[j&1][b[j]] = j;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}