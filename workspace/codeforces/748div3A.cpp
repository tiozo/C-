#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int a,b,c; cin >> a >> b >> c;
        int maxvote = max({a,b,c});
        if (a < maxvote) a = maxvote - a + 1; else a = maxvote - a;
        if (b < maxvote) b = maxvote - b + 1; else b = maxvote - b;
        if (c < maxvote) c = maxvote - c + 1; else c = maxvote - c;
        if (a==b && b!=c && a==0) a = b = 1;
        if (b==c && a!=c && b==0) b = c = 1;
        if (a==c && a!=b && c==0) a = c = 1;
        if (a==b && c==b) a = b = c = 1;
        cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}

/*
    a co the < b va c 
    a co the = b hoac c
    a lon hon
*/