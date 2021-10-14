#include<iostream>
using namespace std;

int main() {
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n;
    scanf("%lld",&n);
    printf("%lld",(1678*n*n*n+3117*n*n+88*n-n%2*345-n%3*320-n%4*90-(n*n*n-n*n+n)%5*288)/240);
    return 0;
}