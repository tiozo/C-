#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m,n,k; cin >> m >> n >> k;
    vector<int> a(m);
    for (int &a:a) cin >> a;
    sort(a.begin(),a.end());
    queue<int> s;
    int ans = -1,tmp = 0;
    for (int i=0;i<a.size();++i) {
        tmp+=a[i];
        s.push(a[i]);
        if (s.size()==n) {
            if (a[i]-s.front()<=k) {
                ans = max(tmp,ans);
                tmp-=s.front();
                s.pop();
            } else {
                tmp-=s.front();
                s.pop();
            }
        }
    }
    if (ans!=-1) cout << ans << '\n'; 
    else cout << "-2\n";
    return 0;
}