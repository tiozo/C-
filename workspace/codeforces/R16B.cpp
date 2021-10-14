#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        int cnt_z =count(s.begin(),s.end(),'0');
        if (cnt_z==0) {
            cout << 0 << '\n';
            continue;
        } else if (cnt_z==s.size()) {
            cout << 1 << '\n';
            continue;
        }
        int first = s.find('0');
        int last = s.rfind('0');
        if (last-first+1==cnt_z) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}