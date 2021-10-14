#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[3001];
const long long oo = 1e18;
const int mod = 2e9+7;
long long memo[3001][3001];
int getAns(int pos,int prev) {
    if (pos>n) return 0;
    if (memo[pos][prev]!= -oo) return memo[pos][prev]%mod;
    int x = a[pos].second + getAns(pos+1,pos);
    // không ghim 
    int y = abs(a[pos].first - a[prev].first) + getAns(pos+1,prev);
    return memo[pos][prev] = min(x,y);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i].first >> a[i].second;
    sort(a+1,a+1+n);
    for (int i=0;i<=n;++i) {
        for (int j=0;j<=n;++j) {
            memo[i][j] = -oo;
        }
    }
    int ans = getAns(2,1)+a[1].second;
    cout << ans;
    return 0;
}