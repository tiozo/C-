#include<bits/stdc++.h>
using namespace std;

const int mxn = 3e5;
int a[mxn+1], p[mxn+1];
char s[mxn+1];

int get_sum(int l,int r) {
    if (l>r) return 0;
    return (l%2==1) ? p[r] - p[l-1] : p[l-1] - p[r];
}

int main() {
    int tc; scanf("%d",&tc);
    while (tc--) {
        int n,q; scanf("%d %d",&n,&q);
        scanf("%s",s);
        for (int i=1;i<=n;++i) {
            a[i] = (s[i-1]=='+'?1:-1);
        }
        p[0] = 0;
        for (int i=1;i<=n;++i) {
            p[i] = p[i-1] + (i%2==1?a[i]:-a[i]);
        }
        while (q--) {
            int l,r; cin >> l >> r;
            if (get_sum(l,r)==0) {
                puts("0");
                continue;
            }
            if ((r-l+1)%2==0) {
                puts("2");
            } else puts("1");
        }
    }
    return 0;
}