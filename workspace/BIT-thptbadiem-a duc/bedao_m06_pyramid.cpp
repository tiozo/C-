#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double long
int32_t main() {
    int X,Y; cin >> X >> Y;
    cout << fixed;
    cout << setprecision(9);
    float A = sqrt(2)*sqrt(X*(X+Y))-X;
    float B = Y - A;
    float C = sqrt(A*A+B*B);
    cout << min(A,B) << ' ' << max(A,B) << ' ' << C << '\n';
    return 0;
}
/*

c^2 = a^2 + b^2
c = X + a 
b = Y - a

Y - X = c - a - a - b
 
a^2 = c^2 - b^2
a = c-X
a = Y-b

a^2 = a*a
a^2 = (c-X)*(Y-b)
a^2 = (c*Y - c*b - X*Y + X*b)
a^2 = (c*(a+b) - (c*b) - (c-a)*(a+b) + (c-a)*b)
a*c + b*c - b*c - c*a - c*b + a^2 + 

X + Y = b + c

a^2 = (b+c)^2 + 2bc

b*c = 2*(Y-a)*(X+a) 

a^2 = (X+Y)^2 + 2*(Y-a)*(X+a)

a^2 = (X+Y)^2 + 2*(Y*X + Y*a - a*X - a^2)

a^2 = (X+Y)^2 + 2*(X*Y+a*(Y-X));

a^2 = (X+Y)^2 + 2*X*Y + 2*a*(Y-X);

a^2 = ()
*/