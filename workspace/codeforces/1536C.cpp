#include<bits/stdc++.h>
using namespace std;

inline pair<int, int> getRatio(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    int n; string s;
    while (tc--) {
        cin >> n >> s;
        int d = 0,k = 0;
        map<pair<int,int>,int> m;
        for (auto c:s) {
            if (c=='D') ++d;
            else k++;
            cout << ++m[getRatio(d,k)] << ' ';
        }
        cout << '\n';
    }
    //return 0;
}