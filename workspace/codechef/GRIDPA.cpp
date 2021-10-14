#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n,K; cin >> n >> K;
        vector<vector<int>> s(n,vector<int>(n));
        for (auto &e:s) {
            for (auto &c:e) {
                char x; cin >> x;
                c = (x=='.'?1:0);
            }
        }
        vector<vector<int>> a(n,vector<int>(n));
        for (auto &e:a) {
            for (auto &c:e) {
                cin >> c;
            }
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(K+1,-1e9)));
        dp[0][0][0] = a[0][0];
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                for (int k=0;i!=0 && k<=K;++k) {
                    if (k!=0) {
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+a[i][j]);
                    }
                    if ((k==0 || k==K) && s[i][j]==1) {
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+a[i][j]);
                    }
                }
                for (int k=0;j!=0 && k<=K;++k) {
                    if (k!=0) {
                        dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]+a[i][j]);
                    }
                    if ((k==0 || k==K) && s[i][j]==1) {
                        dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]+a[i][j]);
                    }
                }
            }
        }
        int ans = -1e9;
        for (auto v:dp[n-1][n-1]) {
            ans = max(ans,v);
        }
        if (ans<0) cout << "-1\n";
        else cout << ans << '\n';
    }
    //return 0;
}