#include<bits/stdc++.h>
using namespace std;

void solve(int start, int end, string &s, int row, int col) {
    int endpoint = 0;
    double one = 0, zero = 0;
    for (int i = start; i < end; ++i) {
        int cur = s[i];
        //cout << cur << ' ';
        for (int bits = 0; bits < 7; ++bits) {
            if ((cur>>bits)&1) {
                ++one;
                endpoint = max(endpoint, bits + 1);
            } else ++zero;
            //cout << ((cur>>bits)&1);
        }
        //cout << '\n';
    }
    //cout << one << ' ' << zero << '\n';
    double ans = one / zero;
    cout << row << ' ' << col * 7 << '\n';
    cout << fixed << setprecision(9) << ans << '\n';
}

int main() {
    //cout << log2('z') << '\n';
    int n; cin >> n;
    string s; cin >> s;
    string alter;
    vector<string> str;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '#') {
            str.push_back(alter);
            alter.clear();
        } else {
            alter += s[i];
        }
    }
    str.push_back(alter);
    alter.clear();
    int mindist = 1e9; 
    for (int i = 0; i < str.size(); ++i) {
        mindist = min((int)str[i].size(), mindist);
    }
    string fin;
    for (int i = 0; i < str.size(); ++i) {
        alter.clear();
        for (int j = 0; j < mindist; ++j) {
            alter += str[i][j];
        }
        fin += alter;
    }
    int row = str.size();
    solve(0, fin.size(), fin, row, mindist);
    return 0;
}