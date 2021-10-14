#include<bits/stdc++.h>
using namespace std;

string s;
int a[20010],n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while (q--) {
        cin >> n;
        bool flag = 1;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (a[1] == 1 && n == 1) {
            cout << "z\n";
            continue;
        }
        if (a[1] == 1 || flag == 0) {
            cout << -1 << '\n';
            continue;
        }
        s = "z";
        a[1]--;
        int pos = 24;
        for (int i=1;i<=n;i++) {
            if (i % 2 == 0) {
                pos = 1;
                int d = 1;
                while (d < a[i]) {
                    if (pos < 0 || pos > 25) {
                        flag = 0;
                        break;
                    }
                    s += ('a' + pos);
                    pos++;
                    d++;
                }
                if (i < n)
                    pos = max(pos, a[i+1]);
                if (pos < 0 || pos > 25) {
                    flag = 0;
                    break;
                }
                s += ('a' + pos);
            } else {
                pos = a[i] - 1;
                int d = 1;
                while (d <= a[i]) {
                    if (pos < 0 || pos > 25) {
                        flag = 0;
                        break;
                    }
                    s += ('a' + pos);
                    pos--;
                    d++;
                }
            }
            if (flag == 0) break;
        }
        if (flag==0) cout << -1 << '\n';
        else cout << s << '\n';
    }
    return 0;
}