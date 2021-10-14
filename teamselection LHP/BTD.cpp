#include<bits/stdc++.h>
using namespace std;

const int maxn = 500005;
int N,Q;
int a[maxn];
pair<int,int> query[maxn],cope[maxn];

int main() {
    cin >> N >> Q;
    int mL = 2e9,mR = -2e9;
    for (int i=1;i<=N;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=Q;++i) {
        cin >> query[i].first >> query[i].second;
        mL = min(mL,query[i].first);
        mR = max(mR,query[i].second);
        cope[i].first = query[i].first;
        cope[i].second = query[i].second;
    }
    sort(cope + 1, cope + 1 + Q);
    //cout << cope[1].first << ' ' << cope[1].second << '\n';
    int res = 0,j = 1;
    map<pair<int,int>,int> M;
    map<int,int> m; multiset<int> s;
    for (int i=mL;i<=mR;++i) {
        m[a[i]]++;
        if (m[a[i]]==2 && s.count(a[i])==0) {
            res++;
            s.insert(a[i]);
        } else if (m[a[i]]>2 && s.count(a[i])==1) {
            res--;
            s.insert(a[i]);
        }
        while (cope[j].first>i || i>cope[j].second) {
            j++;
        }
        if (cope[j].first<=i && i<=cope[j].second) {
            M[cope[j]] = res;
            //cout << res << '\n';
        }
    }
    for (int i=1;i<=Q;++i) {
        cout << M[{query[i]}] << '\n';
    }
    return 0;
}  

/*
    L - > R 
    a[i]==a[j]? 
    trau algo O(Q*(R-L)*log(R-L))
    need only L small to R largest


*/