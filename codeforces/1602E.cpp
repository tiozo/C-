#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int n, m, a[maxn], b[maxn], id[maxn];

struct segtree {
    int seg[4 * maxn], lazy[4 * maxn]; 
    void down(int id){
        if (!lazy[id]){
            return;
        }
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id];
        seg[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    } 
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = l - 1;
            lazy[id] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
        lazy[id] = 0;
    }  
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += val;
            lazy[id] += val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
    }
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 1e9 + 7;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
};

struct fenwick{
    int bit[maxn];
    int n;
    void reset(int n){
        this->n = n + 1;
        for (int i=0;i<=this->n + 1;++i){
            bit[i] = 0;
        }
    }
    int get(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }
    int get(int l, int r){
        return get(r) - get(l - 1);
    }
    void update(int idx){
        for (; idx <= n; idx += idx & -idx){
            bit[idx]++;
        }
    }
};

bool cmp(int i,int j) {
    return a[i] < a[j];
}


struct query{
    int type, pos, idx; // 1: large -> equal, 2: equal -> small, 3: ask
    query() {}; 
    query(int type, int pos, int idx): type(type), pos(pos), idx(idx) {};
    friend bool operator< (const query& lhs, const query& rhs){
        if (lhs.pos != rhs.pos){
            return lhs.pos < rhs.pos;
        }
        if (lhs.type != rhs.type){
            return lhs.type < rhs.type;
        }
        return lhs.idx < rhs.idx;
    }
};

segtree it; fenwick bit;
vector<query> vq;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc; 
    while (tc--) {
        cin >> n >> m;
        for (int i=1;i<=n;++i) cin >> a[i], id[i] = i;
        for (int i=1;i<=m;++i) cin >> b[i];
        it.build(1, 1, n + 1); sort(b + 1, b + 1 + m);
        vq.clear();
        for (int i=1;i<=n;++i) {
            vq.emplace_back(1,a[i],i);
            vq.emplace_back(2,a[i]+1,i);
        }
        for (int i=1;i<=m;++i) {
            vq.emplace_back(3,b[i],0);
        }
        sort(vq.begin(),vq.end());
        long long ans = 0;
        for (auto &que:vq) {
            if (que.type == 1) {
                it.update(1,1,n+1,que.idx+1,n+1,-1);
            } else if (que.type==2) {
                it.update(1,1,n+1,1,que.idx,1);
            } else {
                ans += it.get(1,1,n+1,1,n+1);
            }
        }
        int cntmap = 0; map<int,int> mp;
        for (int i=1;i<=n;++i) {
            mp[a[i]] = 1;
        }
        for (auto &e:mp) {
            e.second += cntmap++;
        }
        for (int i=1;i<=n;++i) {
            a[i] = mp[a[i]];
        }
        bit.reset(cntmap);
        for (int i=1;i<=n;++i) {
            ans += bit.get(a[i]+1,cntmap);
            bit.update(a[i]);
        }
        cout << ans << '\n';
        //it.reset();
    }   
    return 0;
}