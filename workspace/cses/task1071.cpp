#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int tc; cin >> tc;
    while (tc--) {
        int a,b; cin >> a >> b;
        if (a>b) {
            if (a%2==0) cout << (a*a-b+1) << '\n';
            else cout << ((a-1)*(a-1)+b) << '\n';
        } else {
            if (b%2!=0) cout << (b*b-a+1) << '\n';
            else cout << ((b-1)*(b-1)+a) << '\n';
        }
    }
    return 0;
}