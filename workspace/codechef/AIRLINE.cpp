#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int a,b,c,d,e; 
        cin >> a >> b >> c >> d >> e;
        if ((a+b<=d && c<=e) || (a+c<=d && b<=e) || (a<=e && b+c<=d)) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    return 0;
}
/*
ab 
ac
bc */
