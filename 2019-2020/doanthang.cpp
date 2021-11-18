#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return make_tuple(a.second,a.first) < make_tuple(b.second,b.first);
}

int main() {
    int n; cin >> n;
    vector<pair<int,int>> Line(1);
    for (int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        Line.push_back({x, y});
    }
    sort(Line.begin() + 1, Line.end(), cmp);
    int CurR = -(1e9 + 7), ans = 0; 
    for (int i = 1; i <= n; ++i) {
        if (Line[i].first >= CurR) {
            CurR = Line[i].second;
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}