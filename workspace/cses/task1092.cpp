#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a,b;
    if (n%4==0) {
        for (int i=1;i<=n;++i) {
            if (i%4==1 || i%4==0) a.push_back(i);
            else b.push_back(i);
        }
        cout << "YES\n";
        cout << a.size() << '\n';
        for (int &a:a) cout << a << ' ';
        cout << '\n';
        cout << b.size() << '\n';
        for (int &b:b) cout << b << ' ';
    } else if (n%4==3) {
        for (int i=1;i<n;++i) {
            if (i%4==1 || i%4==2) a.push_back(i);
            else b.push_back(i);
        }
        b.push_back(n);
        cout << "YES\n";
        cout << a.size() << '\n';
        for (int &a:a) cout << a << ' ';
        cout << '\n';
        cout << b.size() << '\n';
        for (int &b:b) cout << b << ' ';
    } else cout << "NO";
    return 0;
}