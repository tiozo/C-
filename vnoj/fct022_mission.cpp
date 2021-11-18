#include<bits/stdc++.h>
using namespace std;

const int N = 20;
const pair<int,int> moveset[8] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, 
                                    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
int n;
int dp[N*N][4], a[N][N], cost[N*N][4], d[4][N][N][N][N];
int X[N*N], Y[N*N]; 

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            X[a[i][j]] = i;
            Y[a[i][j]] = j;
            //cout << X[a[i][j]] << ' ' << Y[a[i][j]] << '\n';
        }
    }
    /// BFS horses;
    /// other wise just dp

    for (int i = 1; i <= n*n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cost[i][j] = 1e9;
            dp[i][j] = 1e9;
            //d[j][X[i]][Y[i]] = 1e9;
        }
    }

    for (int j = 1; j <= 3; ++j) {
    /// shortest distant between i and i + 1
        memset(d[j], 0x3f, sizeof d[j]);
        if (j == 1) {
            for (int i = 2; i <= n*n; ++i) {
                if (X[i] == X[i - 1] || Y[i] == Y[i - 1])
                    d[j][X[i - 1]][Y[i - 1]][X[i]][Y[i]] = 1;
                else d[j][X[i - 1]][Y[i - 1]][X[i]][Y[i]] = 2;
            }
        } else 
        if (j == 2) {
            for (int i = 1; i < n*n; ++i) {
                queue<pair<pair<int,int>,int>> q;
                q.push({{X[i], Y[i]}, 0});
                while (!q.empty()) {
                    int u = q.front().first.first, v = q.front().first.second; 
                    int du = q.front().second; q.pop();
                    if (u == X[i + 1] && v == Y[i + 1]) {
                        d[j][X[i]][Y[i]][u][v] = du;
                        break;
                    }
                    for (int z = 0; z < 8; ++z) {
                        int x = u + moveset[z].first, y = v + moveset[z].second;
                        if ( x >= 1 && y >= 1 && x <= n && y <= n && d[j][X[i]][Y[i]][x][y] > du + 1) {
                            d[j][X[i]][Y[i]][x][y] = du + 1;
                            q.push({{x, y}, du + 1});
                        }
                    }
                }
            }
        } else {
            for (int i = 2; i <= n*n; ++i) {
                int x = abs(X[i] - X[i - 1]), y = abs(Y[i] - Y[i - 1]);
                if ((X[i]%2 != X[i - 1]%2 && Y[i]%2 != Y[i - 1]%2) || 
                    (X[i]%2 == X[i - 1]%2 && Y[i]%2 == Y[i-1]%2 ))  
                    if (x == y) {
                        d[j][X[i - 1]][Y[i - 1]][X[i]][Y[i]] = 1;
                    } else {
                        d[j][X[i - 1]][Y[i - 1]][X[i]][Y[i]] = 2;
                    }
            }
        }
    } 

    dp[1][1] = 0, dp[1][2] = 0, dp[1][3] = 0;
    for (int i = 2; i <= n*n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                if (dp[i][k] > dp[i-1][j]+d[k][X[i-1]][Y[i-1]][X[i]][Y[i]]+(j!=k))
                    dp[i][k] = dp[i-1][j]+d[k][X[i-1]][Y[i-1]][X[i]][Y[i]]+(j!=k);
                //cout << dp[i][k] << '\n';
            }
        }
    }

    cost[1][1] = 0, cost[1][2] = 0, cost[1][3] = 0;
    for (int i = 2; i <= n*n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                if (dp[i][k] == d[k][X[i-1]][Y[i-1]][X[i]][Y[i]] + dp[i - 1][j] + (k!=j)) {
                    cost[i][k] = min(cost[i][k], cost[i - 1][j] + (j!=k));
                }
            }
        }
        //cout << i << '\n';
    }
    int X, val = 1e9;
    for (int i = 1; i <= 3; ++i) {
        if (val > dp[n*n][i]) {
            val = dp[n*n][i];
            X = i;
        }
        //cout << dp[n*n][i] << '\n';
    }
    cout << dp[n*n][X] << ' ' << cost[n*n][X] << '\n';
    return 0;
}

/*
    j != k remain because its changed the chess which also a move.
*/

/*
input:
3
7 3 1
4 2 8
9 5 6
*/