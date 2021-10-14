#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7;
const int base = 311;
const int maxn = 2002;
int n,k;

char ccc; /// buff
void read(string &s) {
    while (ccc = getchar(), ccc != '.' && (ccc < 'a' || ccc > 'z'));
    s.assign(1, ccc);
    while (ccc = getchar(), ccc == '.' || (ccc >= 'a' && ccc <= 'z'))
        s += ccc;
}

int fix(int x) {
    while (x < 0) x += mod;
    if (x>=mod) x%=mod;
    return x;
}

int powmod(int x,int n) {
    int res = 1;
    while (n) {
        if (n&1) res = (1ll*res*x)%mod;
        x = (1ll*x*x)%mod;
        n>>=1;
    }
    return res;
}

int P[maxn+1];
int inv_p[maxn+1];
void precal() {
    P[0] = 1;
    for (int i=1;i<=maxn;++i) {
        P[i] = (1ll * P[i-1] * base) % mod;
    }
    inv_p[maxn] = powmod(P[maxn],mod-2);
    for (int i=maxn;i>=1;--i) {
        inv_p[i-1] = (1ll*inv_p[i]*base)%mod;
    }
} 

inline int hash_value(const string &s) {
    int h = 0;
    for (int i=0;i<s.size();++i) {
        h = (h + 1ll * P[i] * s[i]) % mod;
    }
    return h;
} 

inline int hash_concat(int hash_l, int hash_r, int l_size) {
    return (hash_l + 1ll * hash_r * P[l_size]) % mod;
}

inline int hash_rollback(int hash_v, char c, int v_size) {
    return fix((hash_v - 1ll * P[v_size-1] * c) % mod);
}

inline int hash_rollfront(int hash_v, char c) {
    return (ll(hash_v - c) * inv_p[1]) % mod;
}

int mxdict; string tmp;
unordered_set<int> dic;
void input_dic() {
    int q; scanf("%d",&q);
    mxdict = 0;
    dic.insert(-1);
    while (q--) {
        read(tmp);
        dic.insert(hash_value(tmp));
        mxdict = max(mxdict,(int)tmp.size());
    }
}

struct circular {
    int d,n; 
    deque<int> t,H,L;
    int size() {
        return n;
    }
    void pre(const string &s) {
        d = 0; n = s.size();
        for (char c:s) t.push_back(c);
        for (int l = 0, r = 0; l < n; l = r + 1) {
            char c = s[l];
            if (c == '.') {
                for (r = l; r + 1 < n && s[r+1]=='.';++r);
                H.push_back(-1);
                L.push_back(r-l+1);
            } else {
                for (r = l; r+1 < n && s[r+1]!='.';++r);
                H.push_back(hash_value(s.substr(l,r-l+1)));
                L.push_back(r-l+1);
            }
            d += !dic.count(H.back());
        }
    } 
    void rotate_left() {
        char first = t.front();
        int hash_first = (first == '.') ? -1 : first;
        t.push_back(first);
        t.pop_front();

        if ((H.back() == -1) ^ (H.front() == -1)) {
            H.push_back(hash_first);
            L.push_back(1);
            d += !dic.count(H.back());
        } else {
            if (hash_first > -1) {
                d -= !dic.count(H.back());
                H.back() = hash_concat(H.back(),hash_first,L.back());
                d += !dic.count(H.back());
            }
            ++L.back();
        }
        if (L.front() == 1) {
            d -= !dic.count(H.front());
            H.pop_front();
            L.pop_front();
        } else {
            if (hash_first > -1) {
                d -= !dic.count(H.front());
                H.front() = hash_rollfront(H.front(),first);
                d += !dic.count(H.front());
            }
            --L.front();
        }
    }
}a[maxn];

void input_labels() {
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        read(tmp);
        a[i].pre(tmp);
    }
    k = a[1].size();
}

inline bool test() {
    if (a[1].d > 1) return false;
    if (a[n].d > 1) return false;
    int S_cat = -1;
    int L_cat = -1;
    for (int i=1;i<=n+1;++i) {
        bool exist_gap = (i<=n) ? a[i].H.size() > 1 : true;
        int S_pre = (i<=n) ? a[i].H.front() : -1;
        int L_pre = (i<=n) ? a[i].L.front() : -1;
        int S_suf = (i<=n) ? a[i].H.back() : -1;
        int L_suf = (i<=n) ? a[i].L.back() : -1;
        int d = a[i].d;
        if (i>1) d -= !dic.count(S_pre);
        if (i<n) d -= !dic.count(S_suf);
        if (d>0) {
            return false;
        }
        if (S_pre!=-1) {
            if (S_cat != -1) {
                S_cat = hash_concat(S_cat,S_pre,L_cat);
                L_cat += L_pre; 
            } else {
                S_cat = S_pre;
                L_cat = L_pre;
            }   
        }
        if (exist_gap && S_cat!=-1) {
            if (!dic.count(S_cat)) {
                return false;
            } else {
                S_cat = -1;
                L_cat = -1;
            }
        }
        if (S_cat == -1 && S_suf != -1) {
            S_cat = S_suf;
            L_cat = L_suf;
        }
    }
    return true;
}

bool valid[maxn];
void solve() {
    int cnt_valid = 0;
    for (int t = 0; t<k ;++t) {
        if (test()) {
            ++cnt_valid;
            valid[t] = true;
        }
        for (int i=1;i<=n;++i) {
            a[i].rotate_left();
        }
    }
    printf("%d\n",cnt_valid);
    for (int t=0;t<k;++t) {
        if (valid[t]) {
            printf("%d ",t);
        }
    }
}

int main() {
    //freopen("input.inp","r",stdin);
    precal();
    input_dic();
    input_labels();
    solve();
}
