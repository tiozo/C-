#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> a(n); for (int &e:a) cin >> e;
        reverse(all(a));
        vector<int> dp(n+1);
        dp[0] = 0;
        bool flag = a[0]>0?true:false;
        //cout << "flag:" << flag << '\n';
        dp[1] = 1;
        for (int i=2;i<=n;++i) {
            if((a[i-1]>0 && !flag)||(a[i-1]< 0 && flag)) {
                dp[i] = dp[i-1] + 1;
                flag ^= 1;
            } else {
                dp[i] = 1;
                flag = a[i-1] > 0?true:false;
            }
            //cout << "flag:" << flag << '\n';
        }
        reverse(all(dp));
        for (int i=0;i<n;++i) {
            cout << dp[i] << ' '; 
        }
        cout << '\n';
    }
    return 0;
}