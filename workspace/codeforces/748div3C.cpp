#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,k; cin >> n >> k;
        vector<int> mice(k+1,0);
        for (int i=1;i<=k;++i) {
            cin >> mice[i];
        }
        sort(mice.begin() + 1,mice.end());
        int m = 0, remain_time = n, cat = 0; 
        for (int i=k;i>=1;--i) {
            if (cat >= mice[i]) break;
            remain_time -= (n-mice[i]);
            //cout << (n-mice[i]) << ' ' << cat << '\n';
            if (remain_time > 0) ++m; else break;
            ++cat;
        }
        cout << m << '\n';
    }
    return 0;
}