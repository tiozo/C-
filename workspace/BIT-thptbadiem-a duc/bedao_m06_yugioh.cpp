#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6;

int X,n;
int sieve[maxn+10] = {0},p[maxn+10];
bool isGood(int x) {
    if (x>X) return false;
    if (x<=0) return false;
    return sieve[x]==0;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=2;i*i<=maxn;i++) {
        if (!sieve[i]) {
            for (int j=i*i;j<=maxn;j+=i) {
                sieve[j] = i;
            }
        }
    }
    sieve[1] = 1;
    int cnt=0; cin >> n >> X;
    for (int i=0;i<n;++i) {
        int x; cin >> x;
        if (isGood(x)) {
            p[i] = 1;
            ++cnt;
        }
    }
    for (int i=1;i<n;++i) {
        p[i] = p[i-1]+p[i];
    }
    int res = cnt;
    for (int l=0,r=cnt-1;r<n;l++,r++) {
        int cur = p[r];
        if (l) cur -= p[l-1];
        res = min(res,cnt-cur);
    }
    cout << res << '\n';
    return 0;
}