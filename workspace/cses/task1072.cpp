#include<bits/stdc++.h>
using namespace std;
#define int long long
int rec(int n) {
    if (n==1) {
        cout << 0 << '\n';
        return 0;
    }
    int c = 0;
    int t = n*n-1;
    for (int i=1;i<=n;++i) {
        int x = 0;
        if (2<=n && i+2<=n) x++;
        if (3<=n && i+1<=n) x++;
        if (1+2<=n && i-1>0) x++;
		if (1+1<=n && i-2>0) x++;
        c = c + t - x;
        t--;
    }
    for (int i=2;i<=n;++i) {
        int x = 0;
        if (2<=n && i+2<=n) x++;
        if (3<=n && i+1<=n) x++;
        if (1+2<=n && i-1>0 && i!=2) x++;
		if (1+1<=n && i-2>0 && i!=3) x++;
        c = c + t - x;
        t--;
    }
    c = c + rec(n-1);
    cout << c << '\n';
    return c;
}

signed main() {
    ios::sync_with_stdio(false); cout.tie(0);
    int n; cin >> n;
    rec(n);
    //return 0;
}