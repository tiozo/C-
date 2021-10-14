#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int sum[maxn];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        for (int i=0;i<s.size();++i) {
            sum[i+1] = sum[i];
            if (s[i]=='[' || s[i]==']') {
                if (i&1) sum[i+1]++; 
                else sum[i+1]--;
            }
        }
        int q; cin >> q;
        while (q--) {
            int a,b; cin >> a >> b;
            cout << abs(sum[b]-sum[a-1]) << '\n';
        }
    }
    return 0;
}