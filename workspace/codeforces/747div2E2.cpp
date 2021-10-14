#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<string,int> mp;
vector<ll> color[6];
ll dp[(60*10000) + 5][6], c[(60*10000) + 5];
vector<vector<int>> adj;
map<ll,int> label;

const int mod = 1e9 + 7;

ll powmod(ll a,ll b) {
    if (b==0) return 1;
    ll res = 1;
    while (b) {
        if (b&1) res = (1ll * res * a) % mod; 
        a = (1ll * a*a) % mod;
        b >>= 1;
    }
    return res % mod;
}

ll solve(int i,int j) {
    if (c[i]!=-1 && c[i]!=j) {
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];
    ll ans = 0; vector<ll> sum(2,0);
    for (auto x:color[j]) {
        for (int j=0;j<adj[i].size();++j) {
            sum[j] = (sum[j] + solve(adj[i][j],x)) % mod;
        }
    } 
    if (adj[i].empty()) {
        sum[0] = sum[1] = 1;
    }
    if (adj[i].size()==1ll) {
        sum[1] = 1;
    }
    ans = (sum[0] * sum[1]) % mod;
    return dp[i][j] = ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    color[0] = {1,2,4,5};
    color[1] = {0,2,3,5};
    color[2] = {0,1,3,4};
    color[3] = {1,2,4,5};
    color[4] = {0,2,3,5};
    color[5] = {0,1,3,4};
    mp["white"] = 0;
    mp["blue"] = 1;
    mp["red"] = 2;
    mp["yellow"] = 3;
    mp["green"] = 4;
    mp["orange"] = 5;
    memset(dp,-1,sizeof dp);
    memset(c,-1,sizeof c);
    ll k,n; cin >> k >> n;
    ll pos = (1ll<<k) - 1;
    int lab = 0;
    map<ll,int> ar;
    for (int i=0;i<n;++i) {
        ll x; cin >> x; 
        string s; cin >> s;
        ar[x] = mp[s];
        ll cur = x;
        while (cur>=1 && !label.count(cur)) {
            label[cur] = lab;
            lab++; pos--;
            cur /= 2;
        }
    }
    //cout << pos << '\n';
    adj.assign(lab+1,vector<int>());
    for (auto x:label) {
        if (ar.count(x.first)) {
            c[x.second] = ar[x.first];
        }
        if (label.count(x.first * 2)) {
            adj[x.second].push_back(label[x.first*2]);
        }
        if (label.count(x.first * 2 + 1)) {
            adj[x.second].push_back(label[x.first * 2 + 1]);
        }
    }
    ll ans = powmod(4,pos);
    //cout << ans << '\n';
    ll sum = 0;
    for (int j=0;j<6;++j) {
        sum = (sum+solve(label[1],j))%mod;
    }
    ans = (ans*sum)%mod;
    cout << ans;
    return 0;
}