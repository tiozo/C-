#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d",&n);
    vector<int> a(n);
    for (auto &e:a) scanf("%d",&e);
    map<int,int> dp;
    int ans=0,lst=0;
    for (int i=0;i<n;++i) {
        int x = a[i];
        dp[x] = dp[x-1] + 1;
        if (ans<dp[x]) {
            ans = dp[x];
            lst = x;
        }
    }
    vector<int> res;
    for (int i=n-1;i>=0;--i) {
        if (a[i] == lst) {
            res.push_back(i);
            --lst;
        }
    }
    reverse(res.begin(),res.end());
    printf("%d\n",ans);
    for (int i=0;i<res.size();++i) {
        printf("%d ",res[i]+1);
    }
    puts("");
    return 0;
}