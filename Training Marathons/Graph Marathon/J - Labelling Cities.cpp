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
 vector<pair<vector<int>,int>> g;
 vector<set<int>> g2;
 int id[MAXN],out[MAXN],id2[MAXN];
 int cnt;
 void dfs (int u, int par = -1){
    id2[u] = cnt ++;
    for (auto v : g2[u]){
        if (v != par) dfs(v,u);
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].first.push_back(v);
        g[v].first.push_back(u);
    }
    for (int i = 1; i <= n; i++){
         g[i].first.push_back(i);
         sort(all(g[i].first));
         g[i].second = i;
    }
    sort(all(g));
    cnt = 1;
    id[g[1].second] = 1;
    for (int i = 2; i <= n; i++){
        if (g[i].first == g[i-1].first ){
            id[g[i].second] = cnt;
        }else id[g[i].second] = ++cnt;
    }
    g2.resize(cnt+2);
    for (int u = 1; u <= n; u++){
        for (auto v : g[u].first){
            int x = g[u].second;
            if (id[x] != id[v]) g2[id[x]].insert(id[v]);
            if (id[x] != id[v]) g2[id[v]].insert(id[x]);
        }
    }
    int root = 1;
    for (int i = 1; i <= cnt; i++){
       if (g2[i].size() > 2){
             cout << "NO";
             return 0;
       }
       if(g2[i].size() == 1) root = i;
    }
    cnt = 1;
    cout << "YES"<< endl;
    dfs(root);
    for (int i = 1; i <= n; i++) cout <<id2[id[i]] << " ";
 }

