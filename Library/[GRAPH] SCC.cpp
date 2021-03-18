
 //Kosaraju’s algorithm
 int sz, ss, id;
 vector < vector<pair<int,LL>> > g, gr, adj;
 vector<bool> used;
 vector<int> order;
 vector<vector<int>> component;
 LL sum[MAXN],pr[MAXN],scc[MAXN],a[MAXN];
 void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i].first ])
            dfs1 (g[v][i].first);
    order.push_back (v);
 }
void dfs2 (int v) {
    used[v] = true;
    component[id].push_back (v);
    for (auto child : gr[v])
        if (!used[child.first]){
            dfs2 (child.first);
        }
 }
 int main(){
    int n , m;
    cin >> n >> m;
    g.resize(n+2);
    gr.resize(n+2);
    adj.resize(n+2);
    component.resize(n+2);
    used.assign (n+2,false);
    for (int i = 0; i < m; i++){
        int a, b;
        LL w;
        cin >> a >> b >> w;
        g[a].emplace_back(b,w);
        gr[b].emplace_back(a,w);
    }
    int s ;
    cin >> s;
    for (int i = 1; i<= n; ++i)
            if (!used[i])
                dfs1 (i);
     used.assign (n+2, false);
    for (int i = 0; i < n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                for (auto cur : component[id]) scc[cur] = id;
                id++;
              }
        }
    for (int i = 0; i < id ; i++){
        for (auto node : component[i]){
            for (auto child : gr[node]){
                if (scc[node] != scc[child.first]){
                    adj[scc[child.first]].emplace_back(scc[node],child.second);
                }else {
                    a[i] += get(child.second);
                }
            }
        }
    }
    cout << solve(scc[s]);
 }
