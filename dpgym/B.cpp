/*
    source: https://codeforces.com/gym/302977/problem/B
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int K = 27;
const int N = 2e5 + 5;
int n, k;
ll dp[N], a[N];
bool ch[K];
char s[N];

int main() {
    cin >> n >> k;
    cin >> (s + 1);
    for (int i = 1; i <= k; ++i) {
        char c; cin >> c;
        ch[c - 'a'] = true; 
    }
    for (int i = 1; i <= n; ++i) {
        if (ch[s[i] - 'a']) {
            a[i] = 1;
        } else a[i] = 0;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) dp[i] = 0;
        else dp[i] = dp[i - 1] + 1;
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += dp[i];
    }
    cout << sum << '\n';
    return 0;
}