#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int mod = 1e9+7;
const int maxn = 1048610;

int a[maxn];
ll t[4*maxn],prefix;

void build(int id,int l,int r) {
    if (l>r) return;
    if (l==r) {
        t[id] = a[l];
        return;
    }
    int mid = l+((r-l)/2);
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id] = t[id*2]+t[id*2+1];
}

void update(int id,int l,int r,int pos) {
    if (l>r || l>pos || r<pos ) {
        return;
    }
    if (l==r) {
        t[id] = 0; return;
    }
    int mid = l+((r-l)/2);
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    t[id] = t[id*2]+t[id*2+1];
}

int query(int id,int l,int r) {
    if (l>r) return 0;
    if (l==r) {
        return l;
    }
    int mid = l+(r-l)/2;
    if (t[id*2]>t[id*2+1]) {
        return query(id*2,l,mid);
    } else {
        return query(id*2+1,mid+1,r);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k; cin >> k;
    k = 1<<k;
    for (int i=1;i<=k;++i) {
        cin >> a[i];
        prefix += a[i];
    } 
    if (prefix > k+1) {
        return cout << 0,0;
    }
    cout << k << '\n';
    build(1,1,k);
    for (int i=1;i<=k;++i) {
        int idx = query(1,1,k);
        cout << idx << ' ';
        update(1,1,k,idx);
    }
    return 0;
}

/*
Một nút
được coi là ổn định 
nếu giá trị tuyệt đối giữa tổng khối lượng 
của các quả ở cây con trái của nút này 
và tổng khối lượng của các quả ở 
cây con phải của nút này nhỏ hơn hoặc bằng 1.

max(node[id*2],node[id*2+1]) <= 1 else 0;

k = 2
1 1 1 1
\ / \ /
 1   1
  \ /
   1

order take
1 3 2 4

suggest take the most left side on each side for each query.
let take another test case

k = 2
2^2 = 4
1 4 5 2
 4   5 (this have >= 3 for each node)
   5 (this have <= 1 for both side)

sum (l,r)
max(suml(l,r),sumr(l,r));
abs(suml(l,r)-sumr(l,r)) <= 1 then consider to be correct

but through out examples, if all the node diff than 1 than it will be considered wrong
so only need to see if all the value <= 2^k is ok;

*/