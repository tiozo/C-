#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mw = 1e5+10;
int N,W;
int dp[101][mw];

void maxi(int &a,const int &b) {
    if (a<b) a=b;
}

int32_t main() {
    cin >> N >> W;
    vector<pair<int,int>> a(N);
    /// first = weight, second = value
    for (auto &e:a) cin >> e.first >> e.second;
    for (int i=0;i<N;++i) {
        for (int j=0;j<=W;++j) {
            if (j+a[i].first<=W) maxi(dp[i+1][j+a[i].first],dp[i][j]+a[i].second);
            maxi(dp[i+1][j],dp[i][j]);
        }   
    }
    cout << dp[N][W];
    return 0;   
}