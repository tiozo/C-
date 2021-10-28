#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc; 
    while (tc--) {
        string s; cin >> s;
        char min_c = 'z' + 1;
        for (int i=0;i<s.size();++i) {
            min_c = min(s[i],min_c);
        }
        for (int i=0;i<s.size();++i) {
            if (s[i]==min_c) {
                s.erase(s.begin()+i);
                break;
            }
        }
        cout << min_c << ' ' << s << '\n';
    }
    return 0;
}