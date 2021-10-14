#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int a[maxn][maxn], n, m, q;
long long ans = 0;

int main() {
    cin >> n >> m >> q;
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            a[i][j] = 1;
            if (i==0) {
                for (int k=1;;++k) {
                    int x =  i + k/2;
                    int y = j + (k+1)/2;
                    if (x==n || y==m) break;
                    ans += k;
                }
            }
            if (j==0) {
                for (int k=1;;++k) {
                    int x = i + (k+1) / 2;
                    int y = j + k/2;
                    if (x==n || y==m) break;
                    ans += k;
                }
            }
        }
    }
    ans += n*m;
    for (int i=1;i<=q;++i) {
        int x,y; cin >> x >> y;
        --x, --y;
        for (int c=0;c<2;++c) {
            int l = 1, r = 1;
            while (true) {
                int xx = x + (l+c)/2;
                int yy = y + (l + !c)/2;
                if (xx==n || yy==m || a[xx][yy]==0) break;
                ++l;
            }
            while (true) {
                int xx = x - (r+!c)/2;
                int yy = y - (r+c)/2;
                if (xx<0 || yy<0 || a[xx][yy]==0) break;
                ++r;
            }
            if (a[x][y]==0) {
                ans += l*r;
            } else {
                ans -= l*r;
            }
        }
        ans += a[x][y];
        a[x][y] ^= 1;
        ans -= a[x][y];
        cout << ans << '\n';
    }
    return 0;
}

/*
    matrix consist of
    n row m col
    each a[i][j] have 2 state free or locked
    q queries, each consist state of single cell
    after each q how many number of diff staircases
    each only count for 1.
    tio : i don't get it .... how to create the shit
    cre: editorial.
*/