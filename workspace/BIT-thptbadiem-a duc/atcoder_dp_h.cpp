#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int mov[3] = {0,1,0};
const int mod = 1e9+7;
char g[maxn][maxn];
int d[maxn][maxn];

int main() {
    int n,m; cin >> n >> m;
    for (int i=0;i<n;++i) {
        cin >> g[i];
    }
    d[0][0] = 1;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            if (g[i][j]=='#') d[i][j] = 0;
            else {
                if (i>0) d[i][j] = (d[i][j] + d[i-1][j])%mod;
                if (j>0) d[i][j] = (d[i][j] + d[i][j-1])%mod;
                d[i][j]%=mod;
            }
        }
    }
    --n,--m;
    cout << d[n][m];
    return 0;
}