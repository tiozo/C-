#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7;

void add(ll &a,const ll &b) {a=(a+b-mod)%mod;}
ll sub(ll a,const ll &b) {return (a-b+mod)%mod;}

ll dp[100001],prefixsum[100001];

int main() {
    int n,k; cin >> n >> k;
    int tmp;
    dp[0] = 1;
    for (int i=1;i<=n;++i) {
        cin >> tmp;
        for (int j=1;j<=k;++j) {
            dp[j] = (dp[j]+dp[j-1])%mod;
        }
        for (int j=0;j<=k;++j) {
            prefixsum[j] = sub(dp[j],(j>tmp?dp[j-tmp-1]:0));
        }
        swap(dp,prefixsum);
    }
    cout << dp[k];
    return 0;
}