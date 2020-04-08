#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 500 + 9;

struct Dinic {
    const LL flow_inf = 1e18;
    struct FlowEdge {
        int v, u;
        LL cap, flow = 0;
        FlowEdge(int v, int u, LL cap) : v(v), u(u), cap(cap) {}
    };
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, LL cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    LL dfs(int v, LL pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            LL tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    LL flow() {
        LL f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (LL pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
int bx[MAXN],by[MAXN];
int rx[MAXN],ry[MAXN];
LL dist (int i, int j){
    LL x = bx[i] - rx[j];
    LL y = by[i] - ry[j];
    return x * x + y * y;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, b, r;
    cin >> n >> b >> r;
    for (int i = 0; i < b; i++){
        cin >> bx[i] >> by[i];
    }
    for(int i = 0; i < r; i++){
        cin >> rx[i] >> ry[i];
    }
    LL low = 0, hi = 1e9;
    LL ans = 0;
    while (low <= hi){
        LD  mid = (low + hi + 1) / 2;
        Dinic dinic(b+r+2,b+r,b+r+1);
        for (int i = 0; i < b; i++){
            dinic.add_edge(dinic.s,i,1);
            for(int j = 0; j < r; j++){
                if (dist(i,j) < mid) dinic.add_edge(i,b+j,1);
            }
        }
        for (int j = 0; j < r; j++){
            dinic.add_edge(b+j,dinic.t,1);
        }
        if((b + r - dinic.flow())>= n){
            ans = mid;
            low = mid + 1 ;
        }else hi = mid - 1;
    }
    cout << setprecision(20);
    cout << sqrtl(ans);
}