#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &a:a) cin >> a;
    vector<vector<int>> f(n,vector<int>(n));
    for (int i=0;i<n;++i) {
        f[i][0]=a[i];
        f[0][i]=a[i];
    }
    for (int i=1;i<n;++i) {
        for (int j=1;j<n;++j) {
            f[i][j] = a[i]^a[j];
        }
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            cout << f[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}