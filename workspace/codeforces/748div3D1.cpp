#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> a(n); 
        int k = 1e9;
        for (auto &e:a) cin >> e, k = min(k,e);
        bool all_the_same = true;
        for (int i=0;i<n;++i) {
            if (i>0) {
                if (a[i]!=a[i-1]) all_the_same = false; 
            }
        }
        if (all_the_same) {
            cout << "-1\n";
            continue;
        }
        for (int i=0;i<n;++i) {
            a[i] = a[i] - k;
        }
        int ans = a[0];
        for (int i=0;i<n;++i) {
            ans = gcd(a[i],ans);
        }
        cout << ans << '\n';
    }
    return 0;
}