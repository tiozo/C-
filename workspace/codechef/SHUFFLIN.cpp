#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        stack<int> sl;
        stack<int> sc;
        for (int i=1;i<=n;++i) {
            int x; cin >> x;
            if (x%2==0) sc.push(x);
            else if (x%2==1) sl.push(x);
        }
        int ans = 0;
        if (!sl.empty());
            for (int i=2;i<=n && !sl.empty();i+=2) {
                //cout << sl.top()+i << ' ';
                ans += (sl.top()+i)%2; sl.pop();
            }
        //cout << '\n';
        if (!sc.empty())
            for (int i=1;i<=n && !sc.empty();i+=2) {
                //cout << sc.top()+i << ' ';
                ans += (sc.top()+i)%2;  sc.pop();
            }
        //cout << '\n';
        cout << ans << '\n';
    }
    return 0;
}