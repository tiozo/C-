#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const string add[2] = {"RbFR","LFaLb"};
int n;
ll x = 0,y = 0;
string D = "Fa";

string operator -= (const string &a,const string &b) {
    
}

void func(ll x,int steps) {
    if (steps>n || x==0) return;
    if (D[steps]=='a') D += add[0];
    else if (D[steps]=='b') D -= 'b', D += add[1];
    if (D[steps]=='F') y+=1;
    else if (D[steps]=='L') x+=1;
    else if (D[steps]=='R') x-=1;
    func(--x,++steps);
}

int main() {
    ll lim; cin >> lim >> n;
    func(lim,1);
    cout << x << ' ' << y << '\n';
    cout << D << '\n';
    return 0;
}