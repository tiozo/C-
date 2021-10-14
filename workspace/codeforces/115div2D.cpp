#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
using ll = long long;
pair<int,int> a[maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("input.inp","r",stdin);    
    int tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        map<int,int> topics, difficulties;
        vector<vector<int>> input(n,vector<int>(2));
        for (int i=0;i<n;++i) {
            int t,d;
            cin >> t >> d;
            a[i].first = t;
            a[i].second = d;
            topics[t]++; difficulties[d]++;
        }
        ll ans = (n*(n-1)*(n-2))/6;
        for (int i=0;i<n;++i) {
            int t = a[i].first;
            int d = a[i].second;
            ll countT = topics[t] - 1;
            ll countD = difficulties[d] - 1;
            ans -= countT * countD;
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
    overkill way => inclusion-exclusion.
    but way harder and may not worth the effort
*/