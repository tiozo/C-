#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        long long N; cin >> N;
        long long c1,c2;
        c1 = N/3;
        c2 = c1;
        if (N%3==1) {
            c1 += 1;
        } else if (N%3==2) {
            c2 += 1;
        }
        cout << c1 << ' ' << c2 << '\n';
    }
    return 0;   
}