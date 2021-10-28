#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    a-=c; b-=c;
    if (a<0 || b<0) {
        cout << -1; return 0;
    }
    n = n - (a + b + c);
    if (n<1) return cout << -1,0;
    cout << n;
    return 0;
}