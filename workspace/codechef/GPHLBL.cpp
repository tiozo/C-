#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V){os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P){return os << "(" << P.first << "," << P.second << ")";}
#ifndef ONLINE_JUDGE
#define TRACE
#endif
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){ cout << name << " : " << arg1 << endl; }
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);}
#else
#define trace(...) 1
#endif
#define mp make_pair
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define I insert
typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
 
// code credits - http://e-maxx.ru/algo/dinic
struct edge {
    int x, y;
    ll cap, flow;
};
 
struct DinicFlow {
    const ll inf = (1e16);
    vector <edge> e;
    vector <int> cur, d;
    vector < vector <int> > adj;
    int n, source, sink;
 
    DinicFlow() {}
 
    DinicFlow(int v) {
        n = v;
        cur = vector <int> (n + 1);
        d = vector <int> (n + 1);
        adj = vector < vector <int> > (n + 1);
    }
 
    void addEdge(int from, int to, ll cap) {
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0}; 
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }
 
    int bfs() {
        queue <int> q;
        for(int i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while(!q.empty() and d[sink] < 0) {
            int x = q.front(); q.pop();
            for(int i = 0; i < (int)adj[x].size(); ++i) {
                int id = adj[x][i], y = e[id].y;
                if(d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }
 
    ll dfs(int x, ll flow) {
        if(!flow) return 0;
        if(x == sink) return flow;
        for(;cur[x] < (int)adj[x].size(); ++cur[x]) {
            int id = adj[x][cur[x]], y = e[id].y;
            if(d[y] != d[x] + 1) continue;
            ll pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
 
    ll maxFlow(int src, int snk) {
        this->source = src; this->sink = snk;
        ll flow = 0;
        while(bfs()) {
            for(int i = 0; i <= n; ++i) cur[i] = 0;
            while(int pushed = dfs(source, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
 
const int N = 1e5+1;
bool visit[N];
vi dfs_time, rev_adj[N], tmp;
 
int n,m,q,a,b,c1,c2;
int scc[N], scc_cnt, scc_ecnt[N][2];
vi adj[N];
 
void dfs(int f){
    visit[f]=1;
    for(auto z : adj[f]) if(!visit[z]) dfs(z);
    dfs_time.pb(f);
}
 
void dfs2(int f){
    visit[f] = 1; scc[f] = scc_cnt;
    for(auto z : rev_adj[f]) if(!visit[z]) dfs2(z);
}
 
void compute_scc(){
    dfs_time.clear();
    for(int i=1;i<=n;i++)
        if(!visit[i]) dfs(i);
    reverse(dfs_time.begin(), dfs_time.end());
    fill(visit+1, visit+n+1, 0);
    for(int v : dfs_time){
        if(visit[v]) continue;
        scc_cnt++;
        dfs2(v);
    }
    for(int i=1;i<=n;i++){
        scc_ecnt[scc[i]][0] += adj[i].size();
        scc_ecnt[scc[i]][1] += rev_adj[i].size();
    }
}
 
inline void constraint(pii& p, int l, int r){
    p.F = max(p.F, l); p.S = min(p.S, r);
}
 
pii v_cons[N][2], scc_cons[N][2];
ll inf = 1e14;
 
int getMaxFlow(){
    int total = 2*n + 2*scc_cnt;
    int src = ++total, sink = ++total, src1 = ++total, sink1 = ++total;
    DinicFlow g(total);
    ll sat_flow = 0;
    int wrong_flag = 0;
 
    vll demands(total);
 
    auto add_edge = [&](pii c, int u, int v){
        if(c.F > c.S) wrong_flag = 1;
        g.addEdge(u, v, c.S-c.F);
        demands[u] += c.F;
        demands[v] -= c.F;
    };
 
    for(int i=1;i<=n;i++) {
        // middle layer (l3), flow: [0,1]
        for(int j : adj[i]) g.addEdge(i,n+j,1);
        add_edge(v_cons[i][0], 2*n+scc[i], i); //l2
        add_edge(v_cons[i][1], n+i, 2*n+scc_cnt+scc[i]); //l4
    }
    for(int i=1;i<=scc_cnt;i++){
        add_edge(scc_cons[i][0], src, 2*n+i); //l1
        add_edge(scc_cons[i][1], 2*n+scc_cnt+i, sink); //l5
    }
 
    for(int i=1;i<=total-2;i++){
        if(demands[i] < 0) g.addEdge(src1, i, -demands[i]);
        else if(demands[i] > 0) g.addEdge(i, sink1, demands[i]), sat_flow += demands[i];
    }
 
    if(wrong_flag) return -1;
    g.addEdge(sink, src, inf);
    ll mflow = g.maxFlow(src1, sink1);
    if(mflow != sat_flow) return -1;
 
    return g.maxFlow(src, sink);
}
 
ll solve(){
    cin>>n>>m>>q;
    fill(visit, visit+n+1, 0);
    for(int i=1;i<=n;i++) adj[i].clear(), rev_adj[i].clear();
    for(int i=1;i<=n;i++) for(int j : {0,1})
        v_cons[i][j] = {0, m}, scc_cons[i][j] = {0,m}, scc_ecnt[i][j] = 0;
    scc_cnt = 0;
 
    for(int i=0;i<m;i++) cin>>a>>b, adj[a].pb(b), rev_adj[b].pb(a);
    compute_scc();
 
    cin>>c1>>c2;
    int flip = (c1 > c2);
    if(c1 > c2) swap(c1,c2);
 
    for(int i=0;i<q;i++){
        int type, v, label, l, r;
        cin>>type>>v>>label>>l>>r;
        int le = l, re = r;
        label--;
        label ^= flip; 
        if(type <= 2){
            type--;
            if(label){
                int tot = scc_ecnt[scc[v]][type];
                re = tot - l; le = tot - r;
            }
            constraint(scc_cons[scc[v]][type], le, re);
        }
        else{
            type -= 3;
            if(label){
                int tot = type ? rev_adj[v].size() : adj[v].size();
                re = tot - l; le = tot - r;
            }
            constraint(v_cons[v][type], le, re);
        }
    }
 
    int flow = getMaxFlow();
    if(flow == -1) return -1; 
    ll ans = (ll)c1*flow + (ll)c2*(m-flow);
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<'\n';
}