#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn],cnt[33];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i=1;i<=n;++i) {
            cin >> a[i];
        }
        for (int i=0;i<=30;++i) cnt[i] = 0;
        for (int i=1;i<=n;++i) {
            for (int j=0;j<=30;++j) if ((a[i]>>j)&1) {
                cnt[j]++;
            } 
        }
        for (int i=1;i<=n;++i) {
            bool ok = true;
            for (int j=30;j>=0;--j) if (cnt[j]%i!=0) {
                    ok = false;
                    break;
            }
            if (ok) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
    4 4 4 4
    4 & 1 

    a[i]&k + 
*/