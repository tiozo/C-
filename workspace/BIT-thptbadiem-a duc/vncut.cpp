#include<bits/stdc++.h>

#define maxn 5000
#define FOR(i,a,b) for(int i= a;i <= b;++i)
#define REP(i,n) for(int i = 0; i < n ;++i)

using namespace std ;

const long long oo = 1e18;
typedef vector<int> vi ;
long long F[maxn][maxn] ;

void process(int n, int m)
{
    FOR(i,1,n) F[i][i] = 1;
    FOR(i,1,n) { 
        //F[i][i] = 1;
        FOR(j,i+1,m) {
            F[i][j] = oo ;
            FOR(k,1,i/2) {
                F[i][j] = min(F[i][j] ,F[k][j]+F[i-k][j]);
            } 
            FOR(k,1,j/2) {
                F[i][j] = min(F[i][j],F[i][k]+F[i][j-k]);
            }
            F[j][i] = F[i][j];
            //cout << F[i][j] << '\n';
        }
    }
    cout << F[n][m] ;
}

int main()
{
    //freopen("output.out","w",stdout);
    int n, m ;
    cin >> n >> m ;
    if ( n > m )swap(n,m);
    if (n%m==0) {
        cout << n/m << '\n';
        return 0;
    }
    process(n,m) ;
    //system("pause");
    return 0;
}
