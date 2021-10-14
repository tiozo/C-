#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        string s; int res=0; cin >> s;
        vector<int> dp(s.size(),0);
        for (int i=0;i<s.size();++i) {
            if (i==0) continue;
            else if (i==1) {
                if (s[i]==s[i-1]) dp[i] = 0;
                else dp[i] = 1;
            } else {
                if (s[i]==s[i-1]) {
                    dp[i] = dp[i-1];
                } else {
                    dp[i] = max(dp[i-1],dp[i-2]+1);
                }
            }
        }
        cout << dp[s.size()-1] << '\n';
    }
    return 0;
}