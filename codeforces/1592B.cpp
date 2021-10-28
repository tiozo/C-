#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,x; cin >> n >> x;
        vector<int> a(n);
        for (auto &e:a) cin >> e;
        if (n>=2*x) {
            cout << "YES\n";
        } else {
            bool ok = true;
            vector<int> a2 = a;
            sort(a.begin(),a.end());
            for (int i=n-x;i<x;++i) {
                if (a[i]!=a2[i]) {
                    ok = false;
                }
            }
            if (ok) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}