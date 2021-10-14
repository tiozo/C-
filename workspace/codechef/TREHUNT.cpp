#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
int n,m;
long long ans[1000];

void solve() {
    long long pre = 1, res = 0;
    for (long long i=1;i<=n+m-2;++i) {
        res = (res+(ans[i]*pre))%mod;
        pre = (pre*31)%mod;
    }
    cout << res << '\n';
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        memset(ans,0,sizeof ans);
        int a[n][m]; memset(a,1,sizeof a);
        int dp[n][n+m]; memset(dp,0,sizeof dp);
        for (int i=0;i<n;++i) {
            vector<int> v;
            for (int j=0;j<m;++j) {
                if (a[i][j]==1) v.push_back(j);
            }
            int vs = v.size();
            if (vs>=2) for (int j=0;j<=vs-2;++j) for (int k=j+1;k<vs;++k)
                ans[v[k]-v[j]]++;
        }     
        for (int j=0;j<m;++j) {
            vector<int> v;
            for (int i=0;i<n;++i) v.push_back(i);
            int vs = v.size();
            if (vs>=2) for (int i=0;i<=vs-2;++i) for (int k=i+1;k<vs;++k) 
                ans[v[k]-v[i]]++;
        }
        for (int j=0;j<m;++j) {
            for (int i=n-1;i>=0;--i) {
                if (a[i][j]==1) {
                    int x = i+j;
                    if (i>=1) for (int k=0;k<=x-2;++k) {
                        ans[x-k]+=dp[i-1][k];
                    }
                    for (int y=i;y<n;++y) dp[y][x]++;
                }
            }
        }
        //cout << "wot" << '\n';
        for (int i=0;i*2<n-1;++i) {
            for (int j=0;j<m;++j) {
                swap(a[i][j],a[n-1-i][j]);
            }
        }
        memset(dp,0,sizeof dp);
        for (int j=0;j<m;++j) {
            for (int i=n-1;i>=0;--i) {
                if (a[i][j]==1) {
                    int x = i+j;
                    if (i>=1) for (int k=0;k<=x-2;++k) {
                        ans[x-k] += dp[i-1][k];
                    }
                    for (int y=i;y<n;++y) dp[y][x]++;
                }
            }
        }
        solve();
    }
    return 0;
}