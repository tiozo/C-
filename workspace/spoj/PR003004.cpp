/// same as the CPCRC1C but having a slightly bigger input;

#include<bits/stdc++.h>
using namespace std;

int ar[17];
unsigned long long dp[17][1001][2];
unsigned long long getSum(int pos,int n,unsigned long long sum,bool flag) {
    if (pos>n) return sum;
    if (dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];
    int limit = 9;
    if (!flag) limit = ar[pos];
    unsigned long long res = 0;
    for (int i=0;i<=limit;++i) {
        if (flag || i<limit) {
            res += getSum(pos+1,n,sum+i,true);
        } else {
            res += getSum(pos+1,n,sum+i,false);
        }
    }
    return dp[pos][sum][flag] = res;
}

unsigned int digitSum(string a) {
    unsigned int res=0;
    for (int i=0;i<a.size();++i) {
        res+=a[i]-'0';
    }
    return res;
}

int32_t main() {
    int tc; cin >> tc;
    string a,b;
    while (tc--) {
        cin >> a >> b;
        //if (a=="-1") break;
        memset(dp,-1,sizeof dp);
        for (int i=0;i<a.size();++i) {
            ar[i+1] = a[i]-'0';
        }
        unsigned long long L = getSum(1,a.size(),0,0);
        memset(dp,-1,sizeof dp);
        for (int i=0;i<b.size();++i) {
            ar[i+1] = b[i]-'0';
        }
        unsigned long long R = getSum(1,b.size(),0,0);
        cout << (unsigned long long)R-L+digitSum(a) << '\n';
    }
    return 0;
}