#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(int a,int b,int c,int n) {
    if (n==0) return;
    solve(a,c,b,n-1);
    cout << a << ' ' << c << '\n';
    solve(b,a,c,n-1);
}

signed main() {
    int n; cin >> n;
    cout << (1<<n)-1 << '\n';
    solve(1,2,3,n);
    //return 0;
}