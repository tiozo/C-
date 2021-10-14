#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n,k;

int gcd(int a,int b,int &x,int &y) {
    if (a==0) {
        x = 0, y = 1;
        return b;
    }
    int xx, yy,g = gcd(b%a,a,xx,yy);
    x = yy - b / a * xx;
    y = xx;
    return g;
}

int normal(int n) {
    n%=mod; 
    (n<0) && (n+=mod);
    return n;
}

int inv(int a) {
    int x,y; 
    gcd(a,mod,x,y);
    return normal(x);
}

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return int(a * 1ll * b % mod); }
inline int _div(int a, int b) { return mul(a, inv(b)); }

int powmod(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int calc(const vector<int> &y,int x) {
    int ans = 0, k = 1;
    for (int i=1;i<y.size();++i) {
        k = mul(k,normal(x-i));
        k = _div(k,normal(0-i));
    }
    for (int i = 0; i<y.size(); ++i) {
        ans = add(ans,mul(y[i],k));
        if (i+1>=y.size()) break;
        k = mul(k, _div(normal(x - i), normal(x - (i + 1))));
        k = mul(k, _div(normal(i - (y.size() - 1)), normal(i + 1)));
    }
    return ans;
}

inline int solve() {
    vector<int> y;
    int sum = 0;
    y.push_back(sum);
    for (int i=0;i<=k;++i) {
        sum = add(sum, powmod(i + 1, k));
        y.push_back(sum);
    }
    if (n < y.size()) return y[n];
    return calc(y, n);
}

int main() {

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    cin >> n >> k;
    cout << solve() << '\n';
    return 0;
}