#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        bool ok = false;
        int n; cin >> n;
        vector<int> ans;
        string s; char c; cin >> c >> s;
        for (int i=0;i<n;++i) {
            if (s[i]!=c) { 
                ok = true; break;
            }
        }
        //cout << s << ' ' << c << '\n';
        if (!ok) {
            cout << 0 << '\n';
            continue;
        }
        for (int i=1;i<=n;++i) {
            ok = true;
            for (int j=i;j<=n;++j) {
                ok &= (s[j-1]==c);
                j += i-1;
            }
            if (ok) {
                ans.push_back(i); break;
            }
        }
        if (!ok) {
            ans.push_back(n); ans.push_back(n-1);
        }
        cout << ans.size() << '\n';
        for (auto &e:ans) {
            cout << e << ' ';
        }
        cout << '\n';
    }
    return 0;
}