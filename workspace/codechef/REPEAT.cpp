#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int,int>> sum;
void calc() {   
    sum.push_back({0,0});
    //sum.push_back({1,1});
    for (int i=1;i<=N;i+=2) {
        sum.push_back({sum.back().first+i,i});
    }
}

int main() {
    calc();
    int tc; cin >> tc;
    while (tc--) {
        int n,k,s; cin >> n >> k >> s;
        --k;
        //cout << sum[n].first << '\n';
        int gap = s-sum[n].first;
        int tmp;
        while (n) {
            tmp = sum[n--].second;
            //cout << tmp*k << ' ' << gap << '\n';
            if (tmp*k==gap) break;
        }
        cout << tmp << '\n';
    }
    return 0;
}

/*
    3 2 14
    1 1 3 5 = 10
    3 1 3 5 = 12
    5 3 5 1 = 14
    N+K is the largest value;

    5 4 28
    1 3 5 7 9 
    28 - 25 == 3

*/