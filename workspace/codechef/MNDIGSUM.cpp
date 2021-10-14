#include<bits/stdc++.h>
using namespace std;
//#define int long long

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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n,l,r; cin >> n >> l >> r;
        if (r>=n && l<=n) {
            cout << n << '\n';
            continue;
        }
        bool flag = true;
        int mx = INT_MAX,ans = l,i;
        for(i=l;i*i<=n && i<=r;i++) {  
            int tmp = getBase(n,i);
            if (mx>tmp) {
                mx = tmp;
                ans = i;
            }
            if (mx==1) {
                flag = 0;
                break;
            }
        }
        for(;i<=r;++i) {
            int next = min(r,n/(n/i));  
            int tmp = n%next + n/next;
            if (mx>tmp) {
                mx = tmp;
                ans = i;
            }
            if (mx==1) {
                break;
            }
            i = next + 1;
        }
        cout << ans << '\n';
    }
    //cout << getBase(3005,1502) << '\n';
    return 0;
}