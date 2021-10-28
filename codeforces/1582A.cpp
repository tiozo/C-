#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b,c; cin >> a >> b >> c;
    int sum = a*1+b*2+c*3;
    int tmp = sum/2;
    if (tmp*2==sum) {
        cout << 0 << '\n';
    } else {
        cout << abs((sum-tmp)-tmp) << '\n';
    }
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}

/*
1 1 2
1 * 1
2 * 1
3 * 2
3 + 2 = 
*/ 