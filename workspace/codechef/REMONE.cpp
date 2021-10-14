#include<bits/stdc++.h>
using namespace std;
#define all(p) p.begin(),p.end()
#define int long long

struct comp {
    bool operator () (pair<int,int> a,pair<int,int> b) {
        return a.first!=b.first ? a.first < b.first : a.second > b.second;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        map<int,int> m;
        vector<int> a(n);
        vector<int> b(n-1);
        for (int &a:a) cin >> a;
        for (int &b:b) cin >> b;
        sort(all(a)); sort(all(b));
        for (int i=0;i<n-1;++i) {
            m[b[i]-a[i]]++;
            m[b[i]-a[i+1]]++;
            pq.push(make_pair(m[b[i]-a[i]],b[i]-a[i]));
            pq.push(make_pair(m[b[i]-a[i+1]],b[i]-a[i+1]));
        }
        while (pq.top().second<=0) pq.pop();
        cout << pq.top().second << '\n';
    }
    return 0;
}

/*
    4
    1 4 3 8
    15 8 11
    X = 7 vì max_val - max_val = 7 và min_val-min_val = 7
    2 
    4 8 
    10 
    X = 2 
    2
    2 4
    3
    X = 1
    
*/