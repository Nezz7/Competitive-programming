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
int const MAXN = 100 + 9;

//O(V²E)
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
char a[MAXN][MAXN];
int n, m;
bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int col[MAXN * MAXN];
int getId(int i, int j){
    return i * m + j;
}
vector<pair<int,int>> ed;
void dfs(int i, int j,int par, char c){
    col[getId(i, j)] = (i + j) % 2;
    if(par!= -1){
        ed.emplace_back(getId(i,j), par);
    }
    a[i][j] ='X';
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(isValid(x,y) && a[x][y] == c){
            dfs(x, y, getId(i,j), c);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // transform L neighbors C to W
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L')
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(isValid(x,y) && a[x][y] =='C') a[x][y] = 'W';
            }
        }
    }
    int nodes = 0;
    // count C
     for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            nodes += a[i][j] == 'C';
    Dinic d(n* m + 10, n * m, n * m + 1);

    // Generate bipartite graph
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'C') dfs(i,j,-1, 'C');
        }
    }
    // add edges to dinic
    for(auto e : ed){
        if(col[e.first]) swap(e.first, e.second);
        // 0 -> 1
        d.add_edge(e.first, e.second, 1);
    }

    // add edges to S and T
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'X'){
                if(col[getId(i, j)]) {
                    // 1 -> t
                    d.add_edge(getId(i,j),d.t, 1);
                }else d.add_edge(d.s, getId(i,j), 1);

            }
        }
    }
    int ans = nodes - d.flow();

    // count CC of L
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L') dfs(i,j,-1,'L'), ans++;
        }
    }
    cout << ans << endl;
}