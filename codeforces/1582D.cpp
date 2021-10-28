#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,sum = 0; cin >> n;
        vector<int> a(n);
        for (auto &e:a) cin >> e,sum += e;
        int st = 0;
        if (n%2) {
            if (a[0]+a[1]!=0) {
                cout << -a[2] << ' ' << -a[2] << ' ' << a[0] + a[1] << ' ';
            } else if (a[1]+a[2]!=0) {
                cout << a[2]+a[1] << ' ' << -a[0] << ' ' << -a[0] << ' ';
            } else {
                cout << -a[1] << ' ' << a[0] + a[2] << ' ' << -a[1] << ' ';
            }
            st = 3;
        }
        while (st < n) {
            cout << -a[st+1] << ' ' << a[st] << ' ';
            st += 2;
        }
        cout << '\n';
    }
    return 0;
}

/*
    5 5 
    -1 
*/