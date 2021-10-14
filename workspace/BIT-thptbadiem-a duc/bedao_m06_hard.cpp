#include<bits/stdc++.h>
using namespace std;
#define int long long

int INP,AM,REACHEOF;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) { \
    if(!*inp && !REACHEOF) { \
        memset(BUF,0,sizeof BUF);\
        int inpzzz = fread(BUF,1,BUFSIZE,stdin);\
        if (inpzzz != BUFSIZE) REACHEOF = true;\
        inp=BUF; \
    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}

int32_t main() {
    //ios::sync_with_stdio(false); cin.tie(0); 
    set<int> s;
    int q; GN(q);
    while (q--) {
        int type,x; GN(type); GN(x);
        if (type==1) {
            if (s.count(x)) s.erase(x);
            else s.insert(x);
        } else {
            if (!s.count(1)) { puts("-1"); continue; }
            int cur_sum = 0,res = 0;
            while (cur_sum<x) {
                auto it = s.upper_bound(cur_sum+1);
                auto cur = *prev(it);
                int next = x;
                if (it!=s.end()) {
                    next = min(next,(*it)-1);
                }
                int cnt = (next-cur_sum) / cur;
                if (cur_sum+cnt*cur<next) ++cnt;
                res += cnt;
                cur_sum += cnt*cur;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}