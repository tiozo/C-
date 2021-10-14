#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int zeros = 0, c=5;
        while (n/c>0) {
            zeros+=(n/c);
            c=c*5;
        }
        cout << zeros << '\n';
    }
    return 0;   
}