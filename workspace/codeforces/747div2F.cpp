#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int tc; cin >> tc; 
    while (tc--) {
        ll n,k,s; cin >> s >> n >> k;
        if (s==k) {
            cout << "YES\n";
        } else if (s < k) {
            cout << "NO\n";
        } else {
            ll pos = s + k;
            ll l = s - k + 1, r = s;
            ll size = r - l + 1;
            ll num = (s/k)*k;
            ll b = r - num + 1;
            ll a = size - b;
            if ((s/k)%2==1) {
                pos -= b;
            } else {
                pos -= a;
            }
            if ((2 * n + 1) > pos) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}