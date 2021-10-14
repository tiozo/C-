#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,a,b; cin >> n >> a >> b;
        string s; cin >> s;
        int ans = 0;
        for (int i=0;i<s.size();++i) {
            ans += (s[i]=='0'?a:b);
        }
        cout << ans << '\n';
    }
    return 0;
}