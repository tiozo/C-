#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int lps[N];

int main() {
    string t,s;
    cin >> t >> s;
    t = ' ' + t; s = ' ' + s;
    int j;
    j = lps[1] = 0;
    for (int i=2; s[i]; ++i) {
        while (j > 0 && s[j+1] != s[i]) j = lps[j];
        if (s[j+1] == s[i]) ++j;
        lps[i] = j;
    }
    j = 0;
    for (int i=1; t[i]; ++i) {
        while (j > 0 && s[j+1] != t[i]) j = lps[j];
        if (s[j+1] == t[i]) ++j;
        if (s[j+1] == 0) {
            cout << i - j + 1 << ' ';
            j = lps[j];
        }
    }
    return 0;
}