/*
    source: https://codeforces.com/gym/302977/problem/C
*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1111;
int n;
pair<int, char[4]> a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> (a[i].second + 1);
    } 
    
    return 0;
}