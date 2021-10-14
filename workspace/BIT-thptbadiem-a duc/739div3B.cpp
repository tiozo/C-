#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    int a,b,c,d;
    while (tc--) {
        cin >> a >> b >> c;
        long long n = 2*abs(a-b);
        if (a>n || b>n || c>n) {
            cout << -1 << '\n';
        } else {
            long long d = n/2+c;
            while (d>n) d-=n;
            cout << d << '\n';
        }
    }
    return 0;
}