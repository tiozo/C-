#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        long long ans = 0,length;
        int n; cin >> n; 
        int prev;
        for (int i=0;i<n;++i) {
            int x; cin >> x;
            if (i==0) length = 1;
            else {
                if (x>=prev) {
                    ++length;
                } else length = 1;
            }
            ans += length;
            prev = x;
        }
        cout << ans << '\n';
    }
    return 0;
}