#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 1e5+10;
using pq = priority_queue<int,vector<int>,less<> >;
pq a[maxn+1];
//priority_queue<pair<int,int>,vector<int>,less<> > b;
int A,B;
int dp[maxn+1];

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("DIAMOND.inp","r",stdin);
    freopen("DIAMOND.out","w",stdout);
    //memset(dp,-1,sizeof dp);
    int n; cin >> n >> A >> B;
    vector<int> list; set<int> l1;
    vector<int> dis;
    for (int i=1;i<=n;++i) {
        //cout << "done" << '\n';
        int u,v; cin >> u >> v;
        l1.insert(u);
        a[u].push(v);
        //cout << a[u].top() << ' ';
    }
    list.push_back(0); dis.push_back(0);
    for (auto e:l1) {
        dis.push_back(e-list.back());
        list.push_back(e);
    }
    long long ans = 0; stack<pair<int,int>> s;
    for (int i=1;i<list.size();++i) {
        for (int j=1;j<i;++j) 
        while (dis[i]-- && !a[list[j]].empty()) {
            //cout << a[list[i-1]].top() << '\n';
            ans += a[list[i-1]].top(); a[list[i-1]].pop();
        }
    }
    printf("%lld",ans);
    return 0;
}


/*
    naive approach is dp on a and b
    but if you look closely
    you just need O(N) time to chose
    if you already sort the input.
    total runtime isn't O(b-a+1) it is O(nlogn);
*/