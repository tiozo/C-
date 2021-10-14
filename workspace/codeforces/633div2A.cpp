#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()

void solve() {
    int n; cin >> n;
    vector<int>p(n);
    iota(all(p),1);
    for (int &p:p) {
        cout << p << ' ';
    }
    cout << '\n';
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}