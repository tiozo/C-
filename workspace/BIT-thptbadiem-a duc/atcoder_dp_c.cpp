#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int dp[maxn+1][3];

void maximize(int &a,const int &b) {
    if (a<b) a=b;
} 

int main() {
    int n; cin >> n;
    vector<int> e(3);
    for (int i=1;i<=n;++i) {
        cin >> e[0] >> e[1] >> e[2];
        maximize(dp[i][0],max(dp[i-1][1]+e[1],dp[i-1][2]+e[2]));
        maximize(dp[i][1],max(dp[i-1][0]+e[0],dp[i-1][2]+e[2])); 
        maximize(dp[i][2],max(dp[i-1][1]+e[1],dp[i-1][0]+e[0])); 
    }
    cout << max({dp[n][0],dp[n][1],dp[n][2]});
    return 0;
}