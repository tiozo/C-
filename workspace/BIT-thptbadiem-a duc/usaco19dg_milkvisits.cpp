#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int N,M,timer=1;
array<int,2> dat[maxn+1];
int type[maxn+1],C[maxn+1];
bool ok[maxn+1];
pair<int,int> vis[maxn+1];
vector<int> adj[maxn+1],todo[maxn+1];

void dfs(int u,int x) {
    vis[u].first = timer++;
    for (auto &v:adj[u]) {
        if (v!=x) {
            dfs(v,u);
        }
    }  
    vis[u].second = timer-1;
}
vector<pair<int,int>> stor[maxn+1];
vector<int> ord;

bool anc(int u,int v) {
    return vis[u].first <= vis[v].first && vis[v].second<=vis[u].second;
}

void dfs2(int u,int x) {
    stor[type[u]].push_back({x,ord.size()}); ord.push_back(u);
    for (auto v:todo[u]) if (stor[C[v]].size()) {
        auto y = stor[C[v]].back(); 
        if (y.first == x) ok[v] = 1;
        else {
            int Y = ord[y.second+1];
            assert(dat[v][0]==u || dat[v][1]==u);
            if (!anc(Y,dat[v][0]+dat[v][1]-u)) ok[v]=1;
        }
    }
    for (auto v:adj[u]) if (v!=x) dfs2(v,u);
    stor[type[u]].pop_back(); ord.pop_back();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    for (int i=1;i<=N;++i) cin >> type[i];
    for (int i=1;i<N;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for (int i=0;i<M;++i) {
        cin >> dat[i][0] >> dat[i][1] >> C[i];
        for (int k=0;k<2;++k) todo[dat[i][k]].push_back(i);
    }
    dfs2(1,0);
    for (int i=0;i<M;++i) {
        if (ok[i]) cout << 1;
        else cout << 0;
    }
    return 0;
}