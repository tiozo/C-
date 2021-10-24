#include<bits/stdc++.h>
using namespace std;

const int maxn = 1550;
int a[maxn],b[maxn],x[maxn],y[maxn];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n,m; cin >> n >> m;
        for (int i=1;i<=n;++i) {
            cin >> a[i];
            x[i] = 0;
        }
        for (int i=1;i<=m;++i) {
            cin >> b[i];
            y[i] = 0;
        }
        int res = 0;
        for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) {
            int tmp = x[i];
            if (a[i]>=2*b[j]) x[i] = max(x[i],y[j]);
            if (a[i]==b[j]) {
                y[j] = tmp + 1;
                res = max(res,y[j]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}

/*
1
5 5
10 4 6 10 20
5 2 6 10 20 
ans = 2

*/