#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        ll res = 0;
        vector<int> a(n);
        int cnt0=0,cnt1=0;
        for (int i=0;i<n;++i) {
            cin >> a[i];
            if (a[i]==0) cnt0++;
            else if (a[i]==1) cnt1++;
        }
        for(int i = 0; i < n;i++){
            if(a[i] == 1){
                ll dem = 0;
                for(int j = 0; j < n;j++)
                    if(i != j && a[j] == 0)
                        dem++;
                res += (1ll<<dem);
            }
        }
        cout << res << '\n';
    }
    return 0;
}