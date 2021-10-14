#include<bits/stdc++.h>
using namespace std;

int ar[1001];
long long dp[11][1001][2];
long long getSum(int pos,int n,long long sum,bool flag) {
    if (pos>n) return sum;
    if (dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];
    int limit = 9;
    if (!flag) limit = ar[pos];
    long long res = 0;
    for (int i=0;i<=limit;++i) {
        if (flag || i<limit) {
            res += getSum(pos+1,n,sum+i,true);
        } else {
            res += getSum(pos+1,n,sum+i,false);
        }
    }
    return dp[pos][sum][flag] = res;
}

int digitSum(string a) {
    int res=0;
    for (int i=0;i<a.size();++i) {
        res+=a[i]-'0';
    }
    return res;
}

int main() {
    string a,b;
    while (cin >> a >> b) {
        if (a=="-1") break;
        memset(dp,-1,sizeof dp);
        for (int i=0;i<a.size();++i) {
            ar[i+1] = a[i]-'0';
        }
        long long L = getSum(1,a.size(),0,0);
        memset(dp,-1,sizeof dp);
        for (int i=0;i<b.size();++i) {
            ar[i+1] = b[i]-'0';
        }
        long long R = getSum(1,b.size(),0,0);
        cout << R-L+digitSum(a) << '\n';
    }
    return 0;
}