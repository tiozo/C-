#include<bits/stdc++.h>
using namespace std;

using ld = double;

int n;
ld dp[301][301][301];

ld f(int x,int y,int z) {
    if (x<0 || y<0 || z<0) return 0;
    if (x==0 && y==0 && z==0) return 0;
    if (dp[x][y][z]>0) return dp[x][y][z];
    return dp[x][y][z] = (n + x * f(x-1,y,z) + y * f(x+1,y-1,z) + z * f(x,y+1,z-1)) / (x+y+z);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n; vector<int> a(n); vector<int> frequency(4);
    for (auto &e:a) cin >> e, frequency[e]++;
    cout << fixed << setprecision(10) << f(frequency[1],frequency[2],frequency[3]) << '\n';
}