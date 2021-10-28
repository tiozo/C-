#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int oo = 1e9 + 7;
const int maxn = 1e5 + 10;
const int maxk = 450;
int n, a[maxn];
ll prefix[maxn], dp[maxn][maxk];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        prefix[0] = 0;
        for (int i=1; i<=n; ++i) {
            cin >> a[i]; 
            prefix[i] = prefix[i-1] + a[i];
        }
        int k = 0;
        while ((k * (k + 1))/2<=n) ++k;
        for (int i=0;i<k;++i) {
            dp[n+1][i] = -oo;
        } 
        dp[n+1][0] = oo;
        for (int i=n;i>=1;--i) {
            for (int j=0;j<k;++j) {
                dp[i][j] = dp[i+1][j];
                if (j && i + j - 1 <= n && prefix[i+j-1] - prefix[i-1] < dp[i+j][j-1]) {
                    dp[i][j] = max(dp[i][j],prefix[i+j-1]- prefix[i-1]);
                }
            }
        } 
        int ans = 0;
        for (int j=0;j<k;++j) {
            if (dp[1][j] > 0) ans = j;
        }
        cout << ans << '\n';
    }   
    return 0;
}