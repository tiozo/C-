#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("BUFFALO.inp","r",stdin);
    int M,S,C; cin >> M >> S >> C;
    vector<int> cages(C+1,0);
    for (int i=1;i<=C;++i) {
        cin >> cages[i];
    }
    sort(cages.begin()+1,cages.end());
    priority_queue<int,vector<int>,less<> > pq;
    for (int i=2;i<=C;++i) {
        pq.push(cages[i]-cages[i-1]);
        //cout << cages[i]-cages[i-1]+1 << ' ';
    }
    int ans = 0;
    while (M--) {
        cout << pq.top() << ' ';
        ans += pq.top()-2; pq.pop();
    }
    cout << cages[C]-cages[1]-ans;
    return 0;
}

/*
    res<=S
    every cage have buffalo must be fixed 
    this comeback to the smaller problems is the least amount of wood need to be used
    M is the numbers of woods that can be bought.
    S is the numbers of cages
    every x that we have from input is the index of the cage with buff
    this should be minimize to the stack problems.
    THE LEAST NUMBERS OF CAGES NEED TO BE FIXED
    greedy method 
    
*/