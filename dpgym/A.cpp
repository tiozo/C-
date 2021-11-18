/*
    source: https://codeforces.com/gym/302977/problem/A
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 66;
int dp[N];

int main() {
    memset(dp, 0, sizeof dp);
    int n; cin >> n;
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 2 * dp[i - 2];
    }
    cout << dp[n] << '\n';;
    return 0;
}