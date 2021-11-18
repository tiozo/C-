#include<bits/stdc++.h>
using namespace std;

int ask(int c,int d) {
    cout << "? " << c << ' ' << d << '\n';
    int res; cin >> res;
    return res; 
}

int main() {
    cout.flush();
    int a = 0, b = 0, big = ask(0,0); 
    for (int bits = 29; bits >= 0; --bits) {
        int f = (ask(a ^ (1<<bits), b)), s = ask(a, b ^ (1<<bits));
        if (f==s) {
            if (big==1) {
                a ^= (1<<bits);
            } else {
                b ^= (1<<bits);
            }
            big = f;
        }
        else if (f==-1) {
            a ^= (1<<bits); b ^= (1<<bits);
        }
    }
    cout << "! " << a << ' ' << b << '\n';
    return 0;
}