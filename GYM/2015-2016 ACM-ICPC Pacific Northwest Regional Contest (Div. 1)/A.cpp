#include <bits/stdc++.h>
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
int p[MAXN], d[MAXN][MAXN], dist[MAXN][MAXN];
vector < pair < int, pair<int, int> > > a;
int n, m;
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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> d[i][j], dist[i][j] = d[i][j];
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + p[k]+ dist[k][j]);
            }
        }
    }
    for(int i = 0; i < m; i++){
        int s, f, t;
        cin >> s >> f >> t;
        s--;
        f--;
        a.push_back({t, {s, f}});
    }
    sort(all(a));
    Dinic flow(2*m + 2, 0, 2* m + 1);
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            int u = i + 1;
            int v = m + j + 1;
            int s = a[i].second.first;
            int f = a[i].second.second;
            int t = a[i].first + d[s][f] + p[f];
            int s2 = a[j].second.first;
            int f2 = a[j].second.second;
            int t2 = a[j].first;
            if(f != s2) t+= p[s2] + dist[f][s2];
            if(t <= t2) flow.add_edge(u, v, 1);
        }
    }
    for(int i = 1; i <= m; i++) flow.add_edge(0, i, 1);
    for(int i = 1 + m; i <= 2 *m; i++) flow.add_edge(i, flow.t, 1);
    cout << m - flow.flow() << endl;
}