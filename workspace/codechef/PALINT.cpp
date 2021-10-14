#include<bits/stdc++.h>
using namespace std;

pair<int,int> max(pair<int,int> a,pair<int,int> b) {
    if (a.second!=0 || b.second!=0 && a.second!=b.second) {
        return a.second<b.second?b:a;
    }
    if (a.second==b.second) {
        return a.first>b.first?a:b;
    }
    //return a<b?b:a;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,x; cin >> n >> x;
        int ans=0,count=0;
        map<long long,int> m; /// first is so lan, second quy ra operator;
        vector<long long> a(n);
        //stack<int> s1,s2;
        for (int i=0;i<n;++i) {
            cin >> a[i];
            m[a[i]]++;
        }
        for (int i=0;i<n;++i) {
            if (a[i]!=a[i]^x && ans<m[a[i]^x]) {
                ans = m[a[i]]+m[a[i]^x];
                count = m[a[i]^x];
            } else if (a[i]!=a[i]^x && ans==m[a[i]]+m[a[i]^x] && count>m[a[i]^x]) {
                ans = m[a[i]]+m[a[i]^x];
                count = m[a[i]^x];
            } else if (ans<m[a[i]]) {
                ans = m[a[i]];
                count = 0;
            }
        }
        cout << ans << ' '<< count << '\n';
    }
    //cout << max(make_pair(3,0),make_pair(2,1)).second;
    return 0;   
}

