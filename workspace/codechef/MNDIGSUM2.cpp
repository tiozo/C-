#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double double long

const double fifth = 0.2 + 1e-15;
double fractions[3] = { 0.5 + 1e-15, 1.0 / 3.0 + 1e-15, 0.25 + 1e-15 };

static int SmallPower(int n, int k) {
    int r = n;
    for (int i = 1; i < k; ++i)
        r *= n;
    return r;
}

bool getBase(int n,int i,long long &sum) {
    int tmp = 0;
    while (n>0) {
        tmp += n%i;
        n=n/i;
        if (tmp>=sum) return false;
        //cout << n << ' ';
    }   
    sum = tmp;
    return true;
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //sieve();
    int tc; scanf("%lld",&tc);
    while (tc--) {
        int n,l,r,ans=0,mx=1e18; scanf("%lld %lld",&n,&r);
        if (r>=n) {
            printf("%lld\n",n);
            continue;
        }
        int k = n/r, b = r;
        do {
            if (getBase(n,b,mx)) {
                ans = b;
            }
            b = n/(++k);
        } while (b>l && b>k && k<mx);
        if (getBase(n,l,mx)) {
            ans = l;
        }
        int bb = (int)pow(n,fifth);
        int limit = min(bb,r-1);
        for (b = l+1;b<=limit;++b) {
            if (getBase(n,b,mx)) {
                ans = b;
            }
        }
        //cout << "sur";
        for (int j=4;j>=2;--j) {
            if (mx == 1 || limit == r-1)
                break;
            l = bb;
            bb = pow(n,fractions[j-2]);
            limit = min(r-1,bb);
            while (b>l && mx*SmallPower(b,j)>n) {
                if (getBase(n,b,mx)) {
                    ans = b;
                }
                --b;
            }
        }
        printf("%lld\n",ans);
    }
    //cout << getBase(154657894421,2);
    return 0;
}

/*
          
    11011000 ans = 6 is there any link ?
    1   0 /// we dont care about this. this stand alone is nonsense so we wont pick
    2   0 
    4   0
    8   1
    16  1
    32  0
    64  1
    128 1
    256 ~
*/
