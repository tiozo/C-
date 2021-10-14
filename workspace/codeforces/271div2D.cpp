#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int mod = 1e9+7;
int k;
long long pre[maxn+1],dp[maxn+1];
long long getAns(int n) {
    if (n==0) return 1;
    if (dp[n]!=-1) return dp[n];
    long long ans = 0;
    if (n>=k)
        ans += getAns(n-k), ans%=mod;
    ans += getAns(n-1), ans%=mod;
    return dp[n] = ans;
}

void calc() {
    memset(dp,-1,sizeof dp);
    for (int i=1;i<=maxn;++i) {
        pre[i] = (pre[i-1] + getAns(i)), pre[i]%=mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t >> k;
    calc();
    while (t--) {
        int a,b; cin >> a >> b;
        long long sum = (pre[b]-pre[a-1]+mod)%mod;
        cout << sum << '\n';
    }
    return 0;
}