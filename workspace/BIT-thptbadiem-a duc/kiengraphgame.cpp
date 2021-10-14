#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int N,M,L;
int dp[301][301];
int f[301][301][301];

int binominalC(int n,int k) {
    if (k>n) {
        return 0;
    }
    int res = 1;
    if (k>n-k) {
        k = n-k;
    }
    for (int i=0;i<k;++i) {
        res*=(n-i+mod)%mod;
        res/=(i+1);
    }
    return res;
}

int getAns(int n,int m,int prev) {

}

int main() {
    cin >> N >> M >> L;
    N = (N*(N-1))/2;
    cout << binominalC(N,M);
    return 0;
}

/*
    N = 4 M = 4
    N = 4 M = 1 =>  N*(N-1)/2 graphs; (ans = 6)
    N = 4 M = 2 => contains all the prev and new one but must follow the rule 
    each edges only have 2 verticles or less
    P C M
    1 2 3 4 5
*/