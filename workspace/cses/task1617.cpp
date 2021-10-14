#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long s = 1;
    for (int i=1;i<=n;++i) {
        s = 2*s%((int)1e9+7);
    }
    cout << s;
    return 0;
}