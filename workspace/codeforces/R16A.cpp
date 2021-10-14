#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,s; cin >> n >> s;
        if (n==1) {
            cout << s << '\n';
            continue;
        }
        if (s==1 && n>s) {
            cout << 0 << '\n';
            continue;
        }
        long long L = 0, R = s+1;
        while (L<R) {
            auto M = L+(R-L+1)/2;
            auto m = n/2+1;
            if (m*M<=s) {
                L = M; 
            } else R = M-1;
        }
        cout << L << '\n';
    }
    return 0;
}

