#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
long long dp[10010][101];

void init(int l,int d) {
    dp[l][0] = 1;
    for (int i=l-1;i>=0;--i) {
        for (int j=0;j<d;++j) {
            for (int k=0;k<10;++k) {
                dp[i][j] = (dp[i][j] + dp[i + 1][ (j + k) % d]) % mod;
            }
        }
    }
}

int query(const string&s, int d) {
    long long ans = 0, carry = 0;
    for (int i=0;i<s.length();++i) {
        for (int j=0;j<(s[i]-'0');++j) {
            ans = (ans+dp[i+1][(carry+j)%d])%mod;
        }
        carry = (carry+(s[i]-'0'))%d;
    }
    if (carry == 0) ans++;
    if (--ans < 0) ans += mod;
    return (int)ans;
}

int main() {
    string k; int d; cin >> k >> d;
    init((int)k.size(),d);
    cout << query(k,d);
    return 0;
}