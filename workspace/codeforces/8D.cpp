#include<bits/stdc++.h>
using namespace std;

#define sz(a) (int)a.size()

const int mod = 1e9+7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void inc(int& a, int b) { a = add(a, b); }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void dec(int& a, int b) { a = sub(a, b); }

int m,d;
string a,b;

const int maxm = 2000;
int dp[maxm+1][maxm+1][2];
int dpDigit(string s) {
    int n = sz(s);
    for (int i=0;i<=n;++i) {
        for (int j=0;j<m;++j) {
            for (int k=0;k<2;++k) {
                dp[i][j][k] = 0;
            }
        }
    }
    //int ans = 0;
    dp[0][0][1] = 1;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            for (int k=0;k<2;++k) {
                for (int p=0;p<=(k?int(s[i]-'0'):9);++p) {
                    if ((i&1) && p!=d) continue;
                    if (!(i&1) && p==d) continue;
                    if (!i && !p) continue;
                    int ni = i+1;
                    int nj = (j*10+p);
                    int nk = (k && (p==int(s[i]-'0')));
                    inc(dp[ni][nj][nk],dp[i][j][k]);
                    //ans+=dp[ni][nj][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<2;++i) {
        inc(ans,dp[n][0][i]);
        //cout << ans+dp[n][0][i] << '\n';
    }
    return ans;
}

bool good(string s) {
    int rm = 0;
    for (int i=0;i<sz(s);++i) {
        int p = int(s[i] - '0');
        if ((i & 1) && p != d) return false;
        if (!(i & 1) && p == d) return false;
        rm = (rm * 10 + p) % m;
    }
    return !rm;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m >> d;
    assert(cin>>a>>b);
    int ans = 0;
    inc(ans,dpDigit(b));
    dec(ans,dpDigit(a));
    inc(ans,good(a));
    cout << ans << '\n';
    return 0;
}