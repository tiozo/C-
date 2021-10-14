#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct Point {
    long long x,y;
    bool operator < (const Point& a) {return x!=a.x ? x < a.x : y < a.y;}
} p1[maxn], p2[maxn], poly1[maxn], poly2[maxn];

inline bool cross(const Point &a,const Point &b, const Point &c) {
    return 1ll * (a.x-b.x) * (c.y-b.y) - 1ll * (a.y - b.y) * (c.x - b.x) >= 0;
}

void convex(int n, Point p[], int& sz, Point h[]) {
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i) {
        while (sz >= 2 && cross(h[sz - 1], h[sz], p[i]))
        --sz;
        h[++sz] = p[i];
    }
    for (int i = n - 1, t = sz; i >= 1; --i) {
        while (sz > t && cross(h[sz - 1], h[sz], p[i]))
        --sz;
        if (i > 1) h[++sz] = p[i];
    }
}

inline int next(int x, int n) {
  if (x < n) return x + 1;
  return 1;
}
 
inline int prev(int x, int n) {
    if (x > 1) return x - 1;
    return n;
}
 
inline long long sqr(int x) {
    return 1ll * x * x;
}
 
inline long long dist(const Point& a, const Point& b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int n1=0,n2=0;
        for (int i=1;i<=n;++i) {
            int x,y,c; cin >> x >> y >> c;
            if (c==0) {
                ++n1;
                p1[n1].x = x;
                p1[n1].y = y;
            } else {
                ++n2;
                p2[n2].x = x;
                p2[n2].y = y;
            }
        }
        int size1=0,size2=0;
        convex(n1,p1,size1,poly1);
        convex(n2,p2,size2,poly2);
        long long best = 0;
        for (int i=1,j=1;i<=size1;++i) {
            while (dist(poly1[i],poly2[j]) < dist(poly1[i],poly2[next(j,size2)])) j = next(j,size2);
            while (dist(poly1[i],poly2[j]) < dist(poly1[i],poly2[prev(j,size2)])) j = prev(j,size2);
            long long d = dist(poly1[i],poly2[j]);
            if (d>best) best = d;
        }
        long long x = sqrt(best);
        while (sqr(x+1)<=best) ++x;
        cout << x << '\n';
    }
    return 0;
}