#include<bits/stdc++.h>
using namespace std;

mt19937 rng((int)1e7);

int main() {
    freopen("DIAMOND.inp","w",stdout);
    cout << (int)100 <<  ' ' << 1 << ' ' << (int)1e9 << '\n';
    for (int i=1;i<=100;++i) {
        cout << rng() << ' ' << rng() << '\n';
    }
    return 0;
}