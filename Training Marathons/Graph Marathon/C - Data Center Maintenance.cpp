 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int scc[MAXN],a[MAXN],out[MAXN];
 int id;
 vector<bool> used;
 vector<int> order;
 vector<vector<int>> g, gr, c;
 void dfs1 (int node){
    used[node] = true;
    for (auto child : g[node]){
        if (!used[child]) dfs1(child);
    }
    order.push_back(node);
 }
 void dfs2(int node){
    used[node] = true;
    c[id].push_back(node);
    for (auto child : gr[node])
        if (!used[child]) dfs2(child);
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,h;
    cin >> n >> m >> h;
    used.assign(n+1,false);
    c.resize(n+1);
    g.resize(n+1);
    gr.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        if (a[u] < a[v]) swap(u,v);
        if (a[u] - a[v] == 1){
            g[v].push_back(u);
            gr[u].push_back(v);
        }
        if (a[u] == h-1 && a[v] == 0){
            g[u].push_back(v);
            gr[v].push_back(u);
        }
    }
    for (int i = 1;  i <= n; i++)
        if (!used[i]) dfs1(i);
    used.assign(n+1,false);
    reverse(all(order));
    for (auto cur : order){
        if (!used[cur]){
            dfs2(cur);
            for (auto x : c[id]) scc[x] = id;
            id++;
        }
    }
    for (int i  = 1; i <= n; i++){
        for (auto child : g[i]){
            if(scc[i] != scc[child]){
                out[scc[i]]++;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < id ; i++){
        if (out[i] == 0){
            if (ans.size() == 0 or sz(ans) > sz(c[i])) ans = c[i];
        }
    }
    cout << ans.size() << "\n";
    for (auto cur : ans ) cout << cur << " ";
 }
/*
7 8 4
2 1 0 3 3 3 0
4 3
3 2
1 2
1 4
1 3
5 7
7 6
7 5
*/
