#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        long long n; cin >> n;
        if (n==1) {
            cout << 0 << ' ' << 1 << '\n';
            continue;
        } else if (n==2) {
            cout << -1 << ' ' << 2 << '\n';
            continue;
        }
        cout << -(n-1) << ' ' << n << '\n';
    }
    return 0;
}