#include<bits/stdc++.h>
using namespace std;

int d(int a, int b, int c) {
    return (a + c - 2 * b) % 3;
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int a, b, c; cin >> a >> b >> c;
        if (!d(a, b, c)) {
            cout << "0\n";
        } else {
            cout << "1\n";
        }
    }
    return 0;
}

/*
    2 c = a + b
    a or b + 1, then c - 1
    ez to see call d = 2c
    a + b = d
    a + b should be able to 
*/