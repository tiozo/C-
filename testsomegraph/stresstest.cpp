#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    freopen("input.inp","w",stdout);
    int N = 1000;
    int M = N;
    cout << N << ' ' << M << '\n';
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            if ((i==1 || i==N) && (j==1 || j==M)) { cout << 0 << ' '; continue; }
            cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}