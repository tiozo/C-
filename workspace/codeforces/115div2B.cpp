#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int a[maxn][5], n;
map<int,int> m;

void solve() {
    cin >> n;
    for (int i=0;i<n;++i) {
        for (int j=0;j<5;++j) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<5;++i) {
        for (int j=0;j<n;++j) {
            if (a[j][i]) {
                m[i]++;
            }
        }
    } 
    int flag = 0;
    for (int i=0;i<5;++i) {
        for (int j=0;j<5;++j) {
            int tmp = 0;
            if (i!=j) {
                for (int k=0;k<n;++k) {
                    if (a[k][i]==1 || a[k][j]==1) {
                        ++tmp;
                    }
                }
                if (tmp==n && (m[i]>=n/2) && (m[j]>=n/2)) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) break;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    m.clear();
}

int main() {
    int tc; cin >> tc; 
    while (tc--) {
        solve();
    }
    return 0;
}