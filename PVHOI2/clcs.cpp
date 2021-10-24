#include<bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int a[maxn][maxn], prefix[maxn][maxn];
int r, c, h, w;

int getSum(int i,int i_end,int j,int j_end) {
    return prefix[i_end][j_end] - prefix[i-1][j_end] - prefix[i_end][j-1] + prefix[i-1][j-1];
}

bool ok(int level) {
    /// same technic as problem 1 voi 2011.
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (a[i][j] >= level ? 1 : -1);
        }
    }
    for (int i=1;i<=r-h+1;++i) {
        for (int j=1;j<=c-w+1;++j) {
            if (getSum(i,i+h-1,j,j+w-1) > 0) return true;
        }
    }
    return false;
}

int solve() {
    /// this binary search was originally use in the solution
    /// of PVH.
    int L = 1, R = r*c;
    while (true) {
        if (L==R) return R; // or L
        if (R-L==1) return ok(R) ? R : L;
        int M = L+(R-L)/2;
        if (ok(M)) L = M; else R = M - 1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> r >> c >> h >> w;
    for (int i=1;i<=r;++i) {
        for (int j=1;j<=c;++j) {
            cin >> a[i][j];
        }
    }
    /// welp we need to guess what is going to happen next so we can use binary search to smart test all cases
    /// hence all the avail 1 <= p[i][j] <= r*c so we can creat a way to find
    cout << solve() << '\n';
    return 0;
}