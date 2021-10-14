#include <bits/stdc++.h>
using namespace std;
 
long long int C (long long int n, long long int r) {
    long long int res = 1,i;
    if(r > n/2)
            r = n-r;
    for(i = 0; i < r; i++) {
            res *=  n;
            res /= i+1;
            n--;
    }
    return res;
}
 
// Driver code
signed main()
{
    int tc; cin >> tc;
    while (tc--) {
        int n,k; cin >> n >> k;
        int r = n-k; int N = k+r-1;
        cout << C(N,r) << '\n';
    }
    return 0;
}