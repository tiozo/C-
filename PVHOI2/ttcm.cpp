#include<bits/stdc++.h>
using namespace std;

const int maxn = 11;
const int max_eat = 1010;
const int max_turn = 101;
const int mod = 998244353;

int n,e,t,delta;
int cnt[max_turn][max_eat*max_turn];
int sum[max_turn][max_eat*max_turn];
int a[maxn];

void minimize(int &a,const int &b) {
    if (a > b) {
        a = b;
    }
}

void maximize(int &a,const int &b) {
    if (a < b) {
        a = b;
    }
}

void add(int &a,const int &b) {
    a+=b; if (a>=mod) a-=mod;
}

void sub(int &a,const int &b) {
    a-=b; if (a<0) a+=mod;
}

int cntWays(int minA,int maxA) {
    int res = 1;
    for (int i=1;i<=n;++i) {
        int low = minA - a[i];
        int high = maxA - a[i];
        maximize(low,0);
        minimize(high,e*t);
        if (low > high) return 0;
        int mul = sum[t][high];
        if (low>0) sub(mul,sum[t][low-1]);
        res = 1ll * res * mul % mod;
    }
    return res;
}

int main() {
    cin >> n >> e >> t >> delta;
    for (int i=1;i<=n;++i) cin >> a[i];
    cnt[0][0] = 1;
    for (int i=0;i<=t*e;++i) sum[0][i] = 1;
    for (int i=1;i<=t;++i) {
        for (int j=0;j<=i*e;++j) {
            cnt[i][j] = sum[i-1][j];
            if (j>e) sub(cnt[i][j],sum[i-1][j-e-1]);
            sum[i][j] = cnt[i][j];
            if (j>0) add(sum[i][j],sum[i][j-1]);
        }
        for (int j=i*e+1;j<=t*e;++j) {
            cnt[i][j] = 0;
            sum[i][j] = sum[i][j-1];
        }
    }
    int minStart = a[1];
    for (int i=1;i<=n;++i) {
        minimize(minStart,a[i]);
    }
    int res = 0;
    for (int i=minStart; i<=minStart+e*t;++i) {
        int j = i + delta;
        add(res,cntWays(i,j));
        sub(res,cntWays(i+1,j));
    } 
    cout << res << '\n';
    return 0;
}