#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5+1;
int n;
int a[maxn],h[maxn];
int bit[maxn];

void update(int i, int x) {
	for ( ; i <= n; i += i & -i)
		bit[i] = max(bit[i], x);
}

int query(int i) {
    int ans = 0;
	for ( ; i > 0; i -= i & -i)
		ans = max(ans, bit[i]);
	return ans;
}

int32_t main() {
    cin >> n;
    for (int i=1;i<=n;++i) {
        cin >> h[i];
    }
    for (int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for (int i=1;i<=n;++i) {
        update(h[i],query(h[i]-1) + a[i]);
    }
    cout << query(n);
    return 0;
}