#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,ans = 0; cin >> n;
        bool ok = false;
        string s; cin >> s;
        for (int i=0;i<n-1;++i) {
            if (s[i]!=s[i+1] && n>=2) {
                cout << i+1 <<  ' ' << i+2 << '\n';
                ok = 1;
                break;
            } 
        }
        if (!ok) cout << "-1 -1\n";
    }
    return 0;
}