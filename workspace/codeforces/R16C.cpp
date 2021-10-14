#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int ans = count(s.begin(),s.end(),'0');
    int n = s.size();
    bool a = false, b = false;
    for (int i = 0; i < n; ++i) {
        if (s[i]=='0') a = true;
        if (s[i]=='1') b = true;
        if (a && b) {
            ++ans;
            a = b = false;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n,ans = 0; cin >> n;
        string a,b; cin >> a >> b;
        string s = "";
        for (int i=0;i<n;++i) {
            if (a[i]!=b[i]) {
                ans += 2 + solve(s);
                s = "";
            } else {
                s += a[i];
            }
            cout << s << '\n';
        }
        cout << ans + solve(s) << '\n';
    }
    return 0;
}