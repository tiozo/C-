#include<bits/stdc++.h>
using namespace std;
#define int long long

int getBase(int n,int i) {
    int tmp = 0;
    while (n>0) {
        tmp += n%i;
        n=n/i;
        //cout << n << ' ';
    }
    return tmp;
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n,l,r; scanf("%lld %lld",&n,&r);
        if (r>=n) {
            cout << n << '\n';
            continue;
        } else l = n;
        int mx = getBase(n,l),ans = l;
        for(int i=l;i<=min((int)(l+90000),r);i++) {  
            int tmp = getBase(n,i);
            if (mx>tmp) {
                mx = tmp;
                ans = i;
            }
        }
        for(int i=r;i>=max((int)(r-90000),l);i--) {  
           int tmp = getBase(n,i);
            if (mx>=tmp && i<ans) {
                mx = tmp;
                ans = i;
            }
        }
        printf("%lld\n",ans);
    }
    //cout << getBase(3005,1502) << '\n';
    return 0;
}