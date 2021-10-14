#include<bits/stdc++.h>
using namespace std;
#define int long long
#define modulo1(a,b) ((a%mod*b%mod)%mod)
const int mod = (int)1<<63;

int powmod(int a,int b,int p) {
    int res = 1;
    a = a%p;
    if (a==0) return 0;
    while (b>0) {
        if (b&1) res = (res*a)%p;
        b=b>>1;
        a = (a*a)%p;
    }
    return res;
}

int convert(string x) {
    //cout << x.size() << '\n';
    int res = 0,tmp = 1;
    for (int i=x.size()-1;i>=0;--i) {
        res = res + (x[i]-48)*tmp;
        tmp *= 10;
    }
    return res;
}

int32_t main() {
    //string s = "10000";
    //cout << convert(s);
    ios::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while (q--) {
        string bx,by;
        int a1,a2; cin >> a1 >> bx >> a2 >> by;
        if (a1==0 && a2==0) {
            cout << "X = Y\n";
            continue;
        }
        if (a1==0) {
            cout << "X < Y\n";
            continue;
        }
        if (a2==0) {
            cout << "X > Y\n";
            continue;
        }
        int b1=convert(bx),b2=convert(by);
        char equal = '=';
        if (modulo1(a1,powmod(10,b1,mod))>modulo1(a2,powmod(10,b2,mod)))
            equal = '>';
        else if (modulo1(a1,powmod(10,b1,mod))<modulo1(a2,powmod(10,b2,mod)))
            equal = '<';
        cout << "X " << equal << " Y\n";
    }
    return 0;   
}
