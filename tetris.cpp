#include<bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int a[maxn], f[maxn];

void maximize(int &a, int b) {
    if (a < b) a = b;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i) f[i] = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j <= i; ++j)
            if (a[i] > a[j] && tmp < f[j]) {
                tmp = f[j];
            }
        //cout << previous << '\n';
        f[i] = tmp + 1;
    }
    for (int i = 1; i <= n; ++i) {
        maximize(ans, f[i]);
    }
    cout << ans << '\n';
    return 0;
}

/*
6
1 2 5 4 6 2

8
2 1 2 2 2 2 2 3

for (int i = 1; i < n; ++i) {
    int tmp = 0, previous = a[i];
    for (int j = i + 1; j <= n; ++j)
        if (a[j] > previous) {
            tmp++, previous = a[j];
        }
    maximize(ans, tmp);
}
*/