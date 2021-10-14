#include<bits/stdc++.h>
using namespace std;

int n,a,b;
string s;
bool dp[41][40][40][81];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> s;
        for (int i=0;i<a;++i) 
            for (int j=0;j<b;++j) 
                for (int c=-n;c<=n;++c) dp[0][i][j][c+n] = false;
        dp[0][0][0][n] = true;
        for (int i=0;i<n;++i) {
            int cur = s[i] - '0';
            for (int j=0;j<a;++j) 
                for (int k=0;k<b;++k) 
                    for (int l=0;l<=2*n;++l) 
                        dp[i+1][j][k][l] = false;
            for (int j=0;j<a;++j) 
                for (int k=0;k<b;++k) 
                    for (int l=0;l<=2*n;++l)
                        if (dp[i][j][k][l]) {
                            if (l<2*n) dp[i+1][(j*10+cur)%a][k][l+1] = true;
                            if (l>0) dp[i+1][j][(k*10+cur)%b][l-1] = true;
                        }
        }
        int d = -1;
        for (int i=1;i<2*n;++i) if (dp[n][0][0][i]) {
            int x = abs(n-d), y = abs(n-i);
            if (x>y) d=i;
        }
        //cout << d << '\n';
        if (d==-1) cout << -1 << '\n';
        else {
            string ans(n,'_');
            int j=0,k=0,l=d;
            for (int i=n;i--;) {
                int cur = s[i] - '0';
                bool fn = false;
                if (!fn && l>0) {
                    for(int nj=0;nj<a;nj++)if((nj*10+cur)%a==j&&dp[i][nj][k][l-1])
					{
						j=nj;
						l--;
						ans[i]='R';
						fn=true;
						break;
					}
                }
                if(!fn && l<2*n)
				{
					for(int nk=0;nk<b;nk++)if((nk*10+cur)%b==k&&dp[i][j][nk][l+1])
					{
						k=nk;
						l++;
						ans[i]='B';
						fn=true;
						break;
					}
				}
            }
            cout << ans << '\n';
        }
    }
    return 0;
}