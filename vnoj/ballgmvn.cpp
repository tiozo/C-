#include<bits/stdc++.h>
using namespace std;

#define all(p) p.begin(),p.end()

struct cord{
    int x,y,idx;
    bool operator < (const cord &a) const {
        return tie(x,y) < tie(a.x,a.y);
    }
    bool operator == (const cord &a) const {
        return x == a.x && y == a.y;
    }
};

int gcd(int a,int b) {
    if (a<0) a = -a;
    if (b<0) b = -b;
    int r;
    while (b) {
        r = a%b; a = b, b = r;
    }
    return a;
}

void fomalize(cord &a) {
    if (a.y == 0) a.x = 1;
    else if (a.x == 0) a.y = 1;
    else {
        if (a.y < 0) a.y = -a.y, a.x = -a.x;
        int g = gcd(a.x,a.y);
        a.x /= g;
        a.y /= g;
    }
}

bool ok(const cord &a,const vector<cord> &b) {
    int n = b.size();
    vector<cord> c(n);
    for (int i=0;i<n;++i) {
        c[i].x = b[i].x - a.x;
        c[i].y = b[i].y - a.y;
        c[i].idx = b[i].idx;
        fomalize(c[i]);
    }
    sort(all(c));
    for (int i=1;i<n;++i) {
        if (c[i]==c[i-1]) {
            cout << c[i].idx << ' ' << c[i-1].idx << ' ' << a.idx; 
            return true;
        }
    }
    return false;
}

int main() {
    int n; cin >> n;
    vector<cord> a(n),b(n);
    for (int i=0;i<n;++i) {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i + 1;
    }   
    for (int i=0;i<n;++i) {
        cin >> b[i].x >> b[i].y;
        b[i].idx = n + i + 1;
    }
    for (cord &e:a) if (ok(e,b)) return 0;
    for (cord &e:b) if (ok(e,a)) return 0;
    cout << -1 << '\n';
    return 0;
}