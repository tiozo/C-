#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4;
long long sum[10010];
void calc() {
    sum[0] = 0;
    for (int i=1;i<=maxn;++i) {
        sum[i] = sum[i-1]+i;
    }
}

int main() {
    calc();
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        if (n==2) cout << 1 << '\n';
        else if (n==3) cout << n << '\n';
        else {
            if (sum[n]%2==0) cout << n << '\n';
            else cout << n-1 << '\n';
        }
    }
    return 0;
}

/*
    5 
    4
    1 2 3 4 
*/