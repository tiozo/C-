#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &e:a) cin >> e;
    int ans = 1;
    vector<int> pre(n,1);
    vector<int> suf(n,1);
    for (int i=n-2;i>=0;--i) {
        if (a[i+1]>a[i]) suf[i] = suf[i+1] + 1;
        ans = max(ans,suf[i]); 
    }
    for (int i=1;i<n;++i) {
        if (a[i-1]<a[i]) pre[i] = pre[i-1] + 1;
        ans = max(ans,pre[i]);
    }
    for (int i=0;i<n-2;++i) {
        if (a[i]<a[i+2]) ans = max(ans,pre[i]+suf[i+2]);
    }
    cout << ans << '\n';
    return 0;
}