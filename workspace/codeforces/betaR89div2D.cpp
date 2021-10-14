#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int mod = 1e8;
int limit_f, limit_h;
long long dp[101][101][11][11];

int getAns(int f,int h,int k1,int k2) {
    if ((f+h)==0) return 1;
    if (dp[f][h][k1][k2]!=-1) return dp[f][h][k1][k2];
    int x = 0;
    if (f>0 && k1>0) x = getAns(f-1,h,k1-1,limit_h);
    int y = 0;
    if (h>0 && k2>0) y = getAns(f,h-1,limit_f,k2-1);
    return dp[f][h][k1][k2]=(x+y)%mod;
}

signed main() {
    int n1,n2;
    memset(dp,-1,sizeof dp);
    cin >> n1 >> n2 >> limit_f >> limit_h;
    cout << getAns(n1,n2,limit_f,limit_h);
    //eturn 0;
}