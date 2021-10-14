#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int g; cin >> g;
        while (g--) {
            int n,type,ask; 
            cin >> type >> n >> ask;
            if (n%2==0 || type==ask) {
                cout << n/2 << '\n';
            } else cout << n/2+1 << '\n';
        }
    }
    return 0;
}