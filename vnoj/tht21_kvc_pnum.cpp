#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll oo = 1e18;
const int maxn = 2e5 + 5;

int dp[55][12][12][12][12][12], p[6], m, k, d, n;
vector<int> vi(5,0);

int solve(ll pos) {
    if (pos==n) {
        for (int &e:vi) if (e!=10) return 0;
        return 1;
    }
    int &ans = dp[pos][vi[0]][vi[1]][vi[2]][vi[3]][vi[4]];
    if (ans != -1) return ans;
    ans = 0;
    for (int i=0; i<k; ++i) {
        for (int j=0; j<m; ++j) {
            if (pos + 1 >= p[j] && pos + 1 <= p[j] + 9) vi[j] += i; 
        }
        if (*max_element(vi.begin(),vi.end()) <= 10) {
            ans = (ans + solve(pos+1))%d;
        }
        for (int j=0;j<m;++j) {
            if (pos + 1 >= p[j] && pos + 1 <= p[j] + 9) vi[j] -= i;
        }
    }
    return ans;
}

int main() {
    cin >> n >> k >> m >> d;
    for (int i=0;i<m;++i) cin >> p[i];
    memset(dp,-1,sizeof dp);
    for (int i=m;i<5;++i) vi[i] = 10;
    cout << solve(0);
    return 0;
}