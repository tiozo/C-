#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        if (n%25==0) {
            cout << 0 << '\n';
        } else {
            string s = to_string(n);
            int cnt = 0, cur = s.size();
            int res = 0;
            for (int i=s.size()-1;i>=0;--i) {
                if (s[i]=='0') {
                    cur = i;
                    break;
                }
                ++cnt;
            }
            for (int i=cur - 1;i>=0;--i) {
                if (s[i]=='0' || s[i]=='5') {
                    break;
                }
                ++cnt;
            }
            res = cnt;
            cnt = 0;
            for (int i=s.size()-1;i>=0;--i) {
                if (s[i]=='5') {
                    cur = i; break;
                }
                ++cnt;
            }
            for (int i = cur - 1;i>=0;--i) {
                if (s[i]=='2' || s[i]=='7') {
                    break;
                }
                ++cnt;
            }
            res = min(res,cnt);
            cout << res << '\n';
        }
    }
    return 0;
}