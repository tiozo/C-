#include<bits/stdc++.h>

#define left id * 2
#define right id * 2 + 1

#define cur tree[id]
#define lnd tree[left]
#define rnd tree[right]

using namespace std;

const int MAX = 5e5 + 10;
int n, q, arr[MAX], ans[MAX];
pair<int,int> a[MAX];
pair<pair<int,int>,int> ask[MAX];

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first!=b.first ? a.first < b.first : a.second < b.second;
}

bool cmp2(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
    return a.first.first != b.first.first ? a.first.first < b.first.first :
           a.first.second < b.first.second;
}

/// ez to notice that we can't use RMQ becuz this problems required 
/// appearance time of an element x in [L;R]

int preUsed[MAX];
int treeBuild[MAX];

/// start of segment tree

struct node {
    int sum;
    node() {
        sum = 0;
    }
};

node tree[4*MAX];

void join(int id) {
    cur.sum = (lnd.sum + rnd.sum);
}

void build(int id = 1, int l = 1, int r = n) {
    if (l > r) return;
    if (l == r) {
        cur.sum = treeBuild[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    join(id);
}

void update(int id, int l, int r, int u , int v, int val) {
    if (u > r || v < l) return;
    if (l >= u && r <= v) {
        cur.sum = val;
        return;
    }
    int mid = l + (r - l) / 2;
    update(left, l, mid, u, v, val);
    update(right, mid + 1, r, u, v, val);
    join(id);
}

void update(int u, int v, int val) {
    update(1, 1, n, u, v, val);
}

int query(int id, int l, int r, int u, int v) {
    if (u > r || l > v) return 0;
    if (l >= u && r <= v) {
        return cur.sum;
    }
    int mid = l + (r - l) / 2;
    return (query(left, l, mid, u, v) 
            + query(right, mid + 1, r, u ,v));
}

int query(int u, int v) {
    return query(1, 1, n, u, v);
}

//// end of segment tree

vector<int> vec[MAX];
int lastIdx[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    /// compress 
    int c = 1;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        if (a[i].first == a[i-1].first && i > 1) 
            arr[a[i].second] = arr[a[i-1].second];
        else arr[a[i].second] = c++;
    }
    /// done

    for (int i = 1; i <= n; ++i) {
        int x = arr[i];
        //cout << x << '\n';
        if (preUsed[x] == 0) {
            preUsed[x]++;
            treeBuild[i] = 0;
        } else 
        if (preUsed[x] == 1) {
            preUsed[x]++;
            treeBuild[i] = 1;
        } else 
        if (preUsed[x] == 2) {
            preUsed[x]++;
            treeBuild[i] = -1;
        }
        else treeBuild[i] = 0;
        vec[x].push_back(i);
    }
    build();

    for (int i = 1; i <= q; ++i) {
        cin >> ask[i].first.first >> ask[i].first.second;
        ask[i].second = i;
    }

    sort(ask + 1, ask + 1 + q, cmp2);
    
    int Start = 1;
    for (int i = 1; i <= q; ++i) {
        int ask_L = ask[i].first.first;
        while (Start != ask_L) {
            int vecI = arr[Start];
            int updateIndex = vec[vecI][lastIdx[vecI]];
            update(updateIndex, updateIndex, 0);

            if ((int)vec[vecI].size() > lastIdx[vecI] + 1) {
                updateIndex = vec[vecI][lastIdx[vecI] + 1];
                update(updateIndex, updateIndex, 0);
            }
            if ((int)vec[vecI].size() > lastIdx[vecI] + 2) {
                updateIndex = vec[vecI][lastIdx[vecI] + 2];
                update(updateIndex, updateIndex, 1);
            }
            if ((int)vec[vecI].size() > lastIdx[vecI] + 3) {
                updateIndex = vec[vecI][lastIdx[vecI] + 3];
                update(updateIndex, updateIndex, -1);
            }
            lastIdx[vecI]++;
            Start++;
        } 
        //cout << ask[i].first.first << ' ' << ask[i].first.second << '\n';
        int qr = query(ask[i].first.first, ask[i].first.second);
        ans[ask[i].second] = qr;
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}

/*
    the BIT way is the same as this
    /// on vnoj Wutan submission. You have to solve it yourselft first though 

*/