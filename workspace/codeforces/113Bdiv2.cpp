#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; string s;
        cin >> n >> s;
        vector<int> id;
        for (int i=0;i<s.size();++i) {
            if (s[i]=='2') id.push_back(i); 
        }
        int k = id.size();
        if (k==1 || k==2) {
            cout << "NO\n";
            continue;
        }
        vector<string> t(n,string(n,'='));
        for (int i=0;i<n;++i) t[i][i] = 'X';
        for (int i=0;i<k;++i) {
            int x = id[i], y = id[(i+1)%k];
            t[x][y] = '+';
            t[y][x] = '-';
        }
        cout << "YES\n";
        for (int i=0;i<n;++i) cout << t[i] << '\n';
    }
    return 0;
}