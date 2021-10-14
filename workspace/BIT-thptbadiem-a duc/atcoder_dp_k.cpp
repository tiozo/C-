#include<bits/stdc++.h>
using namespace std;

// taro and not taro : D
string Taro = "First", Jiro = "Second";

int main() {
    int n,k; cin >> n >> k;
    vector<bool> dp(k+1,0);
    vector<int> a(n);
    for (int &e:a) cin >> e;
    for (int i=1;i<=k;++i) {
        for (int j:a) {
            if (i>=j && !dp[i-j]) dp[i] = 1;
        }
    }
    cout << (dp[k]?Taro:Jiro) << '\n';
    return 0;
}