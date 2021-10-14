#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int,int> m;
    vector<pair<int,int>> a;
    for (int i=0;i<n;++i) {
        int x; cin >> x;
        m[x]++;
    }
    for (auto &e:m) {
        a.emplace_back(e.first,e.second);
    }
    vector<long long> f(a.size()+1,0);
    for (int i=0;i<a.size();++i) {
        int pr = i-1;
        while (pr>=0 && a[pr].first+1 == a[i].first) pr--;
        if (pr==-1) f[i] = 1LL*a[i].first*a[i].second;
        else f[i] = f[pr]+1LL*a[i].first*a[i].second;
        if (i!=0) f[i] = max(f[i],f[i-1]);
    }
    cout << f[a.size()-1];
    return 0;
}