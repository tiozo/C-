#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
string lib[40];
int lps[N];

int KMP(string &t,string &s) {
    t = ' ' + t; s = ' ' + s;
    int j, res = 0;
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
            ++res;
            j = lps[j];
        }
    }
    return res;
}

int main() {
    lib[1] = "A"; lib[2] = "B";
    for (int i=3;i<=36;++i) {
        lib[i] = lib[i-2] + lib[i-1];
    }
    int N; cin >> N;
    string s; cin >> s;
    cout << KMP(lib[N],s) << '\n';
    return 0;
}