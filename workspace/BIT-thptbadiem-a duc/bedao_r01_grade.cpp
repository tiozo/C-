#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n,q; cin >> n >> q;
    vector<set<int>> a(n+1);
    for (int i=1;i<=n;++i) {
        int s,x; cin >> s;
        while (s--) {
            cin >> x;
            a[i].insert(x);
        }
    }
    while (q--) {
        int k,res = 1,tmp = 1; cin >> k;
        int ele=0;
        for (int i=1;i<=n;++i) {
            if (a[i].count(k)>=1) ++ele;
        }
        if (ele==0) {
            cout << 0 << '\n';
            continue;
        }
        for (int i=1;i<n;++i) {
            if (a[i].count(k)>=1 && a[i+1].count(k)>=1) {
                tmp++;
            } else {
                res = max(res,tmp);
                tmp = 1;
            }
        }
        res = max(res,tmp);
        cout << res << '\n';
    }
    return 0;   
}