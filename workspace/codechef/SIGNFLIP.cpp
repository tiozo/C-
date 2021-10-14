#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,k,sum=0,ans=0; cin >> n >> k;
        priority_queue<int,vector<int>,greater<> > pq;
        for (int i=0;i<n;++i){
            int x; cin >> x;
            if (x>0) sum+=x;
            else if (x<0) pq.push(x);
        }
        int tmp = sum;
        //cout << pq.size() << '\n';
        while (!pq.empty() && k--) {
            tmp += pq.top()*(-1);
            //cout << tmp << '\n';
            pq.pop();
        }
        if (tmp>sum) ans = tmp; else ans = sum;
        cout << ans << '\n';
    }
    return 0;
}