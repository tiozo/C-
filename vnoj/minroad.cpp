#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    return a.first < b.first;
}

int main() {
    int n,A,B; cin >> n >> A >> B;
    vector<pair<int,int>> a(n);
    for (auto &e:a) cin >> e.first >> e.second;
    sort(a.begin(),a.end(),cmp);
    int ans = 1e9 + 7;
    int l = 0;
    int t1=0,t2=0;
    for (int i=0;i<n;++i) {
        if (a[i].second==1) {
            ++t1;
        } else ++t2;
        while (t1>=A && t2>=B) {
            ans = min(a[i].first - a[l].first,ans);
            if (a[l].second==1) {
                --t1;
            } else --t2;
            ++l;
        }
    }
    if (ans == 1e9+7) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}