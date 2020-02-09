 // Solution based on editorial
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
 map <pair<int,int>,int> e;
 vector<vector<int>> g;
 int depth[MAXN],color[MAXN];
 vector<int> p, pp,root,id;
 vector<pair<int,int>> be;
 int find_set (int x){
    if (root[x] == x) return x;
    return root[x] = find_set(root[x]);
 }
 void union_set (int u , int v){
     u = find_set (u);
     v = find_set (v);
    if (u > v) swap(u,v);
    root[v] = u;
 }
 void DFS (int node, int par){
    depth[node] = depth[par] + 1;
    color[node] = 1;
    p[node] = par;
    for (auto child : g[node]){
        if (child == par) continue;
        if (!color[child]) DFS (child,node);
        else if (color[child] == 1)
            be.push_back({node,child});
    }
    color[node] = 2;
 }

 int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n + 1);
    g.resize(n + 1);
    root.assign(MAXN, -1);
    id.assign(n + 1, -1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        e[{u,v}] = i + 1;
        e[{v,u}] = i + 1;
    }
    for (int i = 1; i <= n; i++){
        if (!color[i]) DFS(i,i);
    }
    pp = p;
    int k = be.size();
    vector<int> sizes (k);
    for (int i = 0; i <k ; i++)
        root[i] = i,sizes[i] = 0;
    for (int i = 0; i < k; i++){
        int x = be[i].first;
        vector<int> path;
        while (depth[x] > depth[be[i].second]){
            path.push_back(x);
            if (id[x] == -1){
                 id[x] = i;
            }else
                union_set (i,id[x]);
            x = p[x];
        }
        for (auto j : path)
            p[j] = be[i].second;
    }
    for (int i = 0; i < k ; i++)
        sizes[find_set(i)]++;
    set<int> ans;
    for (int i  = 0; i < k; i++){
        if (sizes[i]  == 1){
            ans.insert(e[{be[i]}]);
            int x = be[i].first;
            while (x != be[i].second){
                 ans.insert(e[{x,pp[x]}]);
                 x = pp[x];
            }
        }
    }
    cout << sz(ans) << endl;
    for (auto cur : ans) cout << cur << " ";
 }
