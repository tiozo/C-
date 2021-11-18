#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {
    #ifndef TioZo
        freopen("input.inp", "r", stdin);
    #endif
    int N; cin >> N;
    vector<pair<int,int>> Line(1);
    for (int i = 1; i <= N; ++i) {
        int x, l; cin >> x >> l;
        Line.push_back({x - l, x + l});
    }
    sort(Line.begin() + 1, Line.end(), cmp);
    int CurR = -1e9, res = 0; 
    for (int i = 1; i <= N; ++i) {
        if (CurR <= Line[i].first) {
            CurR = Line[i].second;
            ++res;
        }
    }
    cout << res << '\n';
    return 0;
}