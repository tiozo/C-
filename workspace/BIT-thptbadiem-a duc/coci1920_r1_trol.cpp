#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
    int q; cin >> q;
    while (q--) {
        ull l,r; cin >> l >> r;
        ull total = r-l+1;
        ull cases = (total)/9*9*10/2;
        for (int i=0;i<total%9;++i) {
            int add = (l+i)%9;
            if (add==0) add = 9;
            cases += add;
        }
        cout << cases << '\n';
    }
    return 0;
}