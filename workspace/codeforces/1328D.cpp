#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto &e:a) cin >> e;
    if (count(a.begin(),a.end(),a[0])==n) {
        cout << 1 << '\n';
        for (int i=0;i<n;++i) {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
    if (n%2==0) {
        cout << 2 << '\n';
        for (int i=0;i<n;++i) {
            cout << i%2+1 << ' ';
        }
        cout << '\n'; return;
    }
    for (int i=0;i<n;++i) {
        if (a[i]==a[(i+1)%n]) {
            vector<int> ans(n);
            for (int j=0,pos=i+1;pos<n;++pos,j^=1) {
                ans[pos] = j+1;
            }
            for (int j=0,pos=i;pos>=0;--pos,j^=1) {
                ans[pos] = j+1;
            }
            cout << 2 << '\n';
            for (int pos=0;pos<n;++pos) {
                cout << ans[pos] << ' ';
            }
            cout << '\n'; return;
        }
    }
    cout << 3 << '\n';
    for (int i=0;i<n-1;++i) {
        cout << i%2+1 << ' ';
    }
    cout << 3 << '\n';
}

int main() {
    int tc; cin >> tc; 
    while (tc--) {
        solve();
    }
    return 0;
}