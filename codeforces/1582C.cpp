#include<bits/stdc++.h>
using namespace std;

int n;
string s;

bool isPalin(string s) {
    int L = 0, R = s.size()-1;
    while (L<=R) {
        //cout << s[L] << ' ' << s[R] << '\n';
        if (s[L]==s[R]) ++L,--R;
        else return false;
    }
    return true;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> s;
        int res = 1e9+7;
        for (char c = 'a'; c<='z';++c) {
            int best = 0; int L=0, R=n-1;
            while (L<R) {
                if (s[L]==s[R]) {
                    ++L,--R;
                } else if (s[L]==c) {
                    ++best, ++L;
                } else if (s[R]==c) {
                    ++best, --R;
                } else {
                    best = n + 1;
                    break;
                }
            }
            res = min(res,best);
        }
        if (res>n) res = -1;
        cout << res << '\n';
    }
    return 0;
}

/*
    only 26 possible way to delete
*/