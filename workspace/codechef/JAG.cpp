#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()
int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,cc; cin >> n;
        cc=n;
        vector<int> a(n);
        for (int i=0;i<n;++i) {
            cin >> a[i];
        }
        bool flag = 1;
        for (int i=1;i<n;++i) {
            if (a[0]!=a[i]-i) {
                flag = 0;
                break;
            }
        }
        if (flag==0) {
            cout << "1\n";
        } else {
            cout << n << "\n";
        }
    }
    return 0;
}