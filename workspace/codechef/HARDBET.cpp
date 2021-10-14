#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int a,b,c; cin >> a >> b >> c;
        if (c<a && c<b) cout << "Alice \n";
        else if (b<a && b<c) cout << "Bob \n";
        else cout << "Draw \n";
    }
    return 0;
}