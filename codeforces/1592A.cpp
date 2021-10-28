#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,hp; cin >> n >> hp; 
    priority_queue<int> pq;
    int sum = 0;
    for (int i=1; i<=n;++i) {
        int a; cin >> a;
        pq.push(a);
        /*if (a > hp) {
            cout << 1 << '\n';
            return;
        }*/
    }
    int times = 0;
    int largest = pq.top(); pq.pop();
    int second_largest = pq.top();
    if (hp % (largest + second_largest) == 0) {
        cout << 2*(hp/(largest+second_largest)) << '\n';
    } else if (hp%(largest+second_largest)<=largest) {
        cout << 2*(hp/(largest+second_largest)) + 1 << '\n';
    } else {
        cout << 2*(hp/(largest+second_largest)) + 2 << '\n';
    }
    //cout << largest << ' ' << second_largest << '\n';
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}