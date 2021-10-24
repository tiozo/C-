#include<bits/stdc++.h>
using namespace std;

class BIT {
private: 
    static const int log_N = 20;
    vector<int> v; int n;
public:
    BIT(int n = 0) {
        this->n = n;
        v.assign(n+7,0);
    };
    void update(int p,int val) {
        for (;p<=n;p+=p&-p) {
            v[p] += val;
        }
    }
    int get(int p) {
        int res = 0;
        for (;p;p-=p&-p) {
            res += v[p];
        }
        return res;
    }
    int lowb(int val) const {
        int res = n+1;
        int tmp = 0;
        for (int i=log_N;i>=0;--i) if ( (tmp|(1ll<<i)) <= n) {
            if (v[tmp|(1ll<<i)]>=val) {
                res = tmp | (1ll<<i);
            } else {
                tmp |= (1ll<<i);
                val -= v[tmp];
            }
        }
        return res;
    }
};

class IT {
private: 
    static const int oo = 1e9 + 7;
    vector<int> tree,lazy;
    int n;
    void shift(int i) {
        for (int j=2*i;j<=2*i+1;++j) {
            tree[j] += lazy[i];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }
    void update(int id,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        if (u<=l && r<=v) {
            tree[id] += c;
            lazy[id] += c;
            return;
        }
        shift(id);
        int m = (l+r)>>1;
        update(id*2,l,m,u,v,c);
        update(id*2+1,m+1,r,u,v,c);
        tree[id] = min(tree[id*2],tree[id*2+1]);
    }
    int getMin(int id,int l,int r,int u,int v) {
        if (l>v || r<u || l>r || v<u) return oo;
        if (u<=l && r>=v) return (tree[id]);
        shift(id);
        int m = (r+l)>>1;
        int L = getMin(id*2,l,m,u,v);
        int R = getMin(id*2+1,m+1,r,u,v);
        return min(L,R);
    }
    int FLPos(int id,int l,int r,int pos,int lim) {
        if (l>pos || r<1 || l>r || pos<1) return n + 1;
        if (1<=l && r<=pos) {
            if (tree[id] >= lim) return l;
            int res = n + 1;
            while (true) {
                if (l==r) return tree[id] >= lim ? r : res;
                shift(id);
                int m = l+(r-l)/2;
                if (tree[id*2+1] >= lim) {
                    res = m + 1;
                    id = id * 2;
                    r = m;
                } else {
                    id = id * 2 + 1;
                    l = m + 1;
                }
            }
        }
        shift(id);
        int m = (r+l)>>1;
        if (pos <= m) return FLPos(id*2,l,m,pos,lim);
        int tmp = FLPos(id*2+1,m+1,r,pos,lim);
        return tmp != m + 1 ? tmp : min(tmp,FLPos(id*2,l,m,pos,lim));
    }
public: 
    IT(int n = 0) {
        this->n = n;
        if (n>0) {
            tree.assign(4*n+7,0);
            lazy.assign(4*n+7,0);
        }
    }
    int getMin(int l,int r) {
        return getMin(1,1,n,l,r);
    }
    void update(int l,int r,int c) {
        update(1,1,n,l,r,c);
    }
    int findLeftPos(int pos,int lim) {
        return FLPos(1,1,n,pos,lim);
    }
};

BIT fen;
IT seg;
const int maxn = 1e6 + 10;
char s[maxn];
int n,q;

void change(int pos) {
    if (s[pos]=='(') {
        s[pos] = ')';
        fen.update(pos,1);
        seg.update(pos,n,-2);
    } else {
        s[pos] = '(';
        fen.update(pos,-1);
        seg.update(pos,n,2);
    }
}

int main() {
    scanf("%d%d",&n,&q);
    scanf("%s",s + 1);
    fen = BIT(n);
    seg = IT(n);
    for (int i=1;i<=n;++i) {
        if (s[i]==')') fen.update(i,1);
    }
    int deg = 0;
    for (int i=1;i<=n;++i) {
        if (s[i]=='(') ++deg; else --deg;
        seg.update(i,i,deg);
    }
    while (q--) {
        int pos; scanf("%d",&pos);
        change(pos);
        int toRev = s[pos] == ')' ? fen.lowb(1) : seg.findLeftPos(pos,2);
        //cout << fen.lowb(1) << ' ' << seg.findLeftPos(pos,2) << '\n';
        printf("%d ",toRev);
        change(toRev);
    }
    return 0;
}