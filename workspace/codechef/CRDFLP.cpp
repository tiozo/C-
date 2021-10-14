#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<int> a(n); for (auto &v:a) cin >> v;
        vector<int> b(n); for (auto &v:b) cin >> v;
        vector<int> state(n,-1);
        for (int mask = (1<<29);mask>0;mask/=2) {
            bool pos = true;
            for (int x=0;x<n && pos;++x) {
                if (state[x]==0 && !(a[x]&mask)) pos = false;
                else if (state[x]==1 && !(b[x]&mask)) pos = false;
                else if (!(a[x]&mask) && !(b[x]&mask)) pos = false;
            }
            if (!pos) continue;
            for(int x = 0; x < n; x++){
                if(state[x] != -1) continue;
                if(!(a[x]&mask)) state[x] = 1;
                else if(!(b[x]&mask)) state[x] = 0;
            }
        }
        int ans = (1<<30)-1, total = 0;
        for(int x = 0; x < n; x++){
            if(state[x] == 1) ans &= b[x], total++;
            else ans &= a[x];
        }
        cout << ans << " " << total << "\n";
    }
    return 0;
}