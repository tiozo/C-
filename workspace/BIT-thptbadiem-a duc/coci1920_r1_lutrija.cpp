#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll a,b;
bool vis[15];

bool check(ll n) {
    if (n<2) return false; 
    for (ll i=2;i*i<=n;++i) {
        if (n%i==0) return false;
    }
    return true;
}

vector<ll> v;
vector<ll> tmp, p;
void dfs(int u) {
    vis[u] = 1;
    tmp.push_back(v[u]);
    if (v[u]==b) {
        if (p.empty() || p.size() > tmp.size()) p = tmp;
        tmp.pop_back();
        return;
    }
    for (int i=0;i<v.size();++i) {
        if (!vis[i] && check(max(v[i]-v[u],v[u]-v[i]))) {
            dfs(i);
            vis[i] = 0;
        } 
    }
    tmp.pop_back();
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for (ll i=a-2;i<=a+2;++i) 
        if (check(i)) v.push_back(i);
    for (ll i=b-2;i<=b+2;++i) {
        if (check(i)) v.push_back(i);
    }
    v.push_back(2);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for (int i=0;i<v.size();++i) {
        if (v[i]==a) {
            vis[i] = 1;
            dfs(i);
        }
    }
    if (p.empty()) cout << "-1\n";
    else {
        cout << p.size() << '\n';
        for (auto x:p) cout << x << ' ';
    }
    return 0;
}