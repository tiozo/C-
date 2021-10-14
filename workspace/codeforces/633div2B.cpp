#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()

void solve() {
    int n,m; cin >> n >> m;
    vector<string> g(n);
    for (auto &s:g) {
        cin >> s;
    }
    int ans = 0;
    for (int i=n-1;i>=0;--i) {
        ans+=g[i][m-1]=='R';
    }
    for (int i=m-1;i>=0;--i) {
        ans +=g[n-1][i] == 'D'; 
    }
    cout << ans << '\n';
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}