#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
int f[N+1];

int main() {
    for (int i = 2; i <= N; i++)
        if (!f[i]) 
            for (int j = i+i; j <= N; j += i) 
                if (!f[j]) f[j] = i;
    int tc; cin >> tc;
    map<int,int> m;
    while (tc--) {
        int n; scanf("%d", &n);
        map<int, int> m;
        while (n--) {
            int x; scanf("%d", &x);
            while (x >= 2 && f[x]) {
                m[f[x]]++;
                x /= f[x];
            }
            if (x >= 2) m[x]++;
        }
        long long res = 1;
        for (map<int, int>::iterator it(m.begin()); it != m.end(); it++)
            res *= (it->second + 1);
        cout << res << '\n';
    }
    return 0;
}