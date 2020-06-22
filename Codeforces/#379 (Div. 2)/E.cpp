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
int const MAXN = 2e6 + 9;
int dp[MAXN], col[MAXN];
vector<vector<int>> g;
vector<pair<int,int>> edges;
int root[MAXN], size[MAXN];
int vis[MAXN];
int find_set(int x){
    if(root[x] == x) return x;
    return root[x] = find_set(root[x]);
}
void union_set(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u == v) return;
    if(size[u] < size[v]) swap(u,v);
    size[u] += size[v];
    root[v] = u;
}
int ans = 0,x;
 void dfs (int node ,int c,int o){
    vis[node] = true;
    c++;
    for (auto child : g[node]){
        if (!vis[child]){
            if (c >= ans &&  o != child){ ans = c, x = child;}
            dfs(child,c,o);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++){
        root[i] = i;
        size[i] = 1;
        cin >> col[i];
    }
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        if(col[u] == col[v]) union_set(u,v);
        else {
            edges.emplace_back(u,v);
        }
    }
    for(auto e : edges){
        int u = find_set(e.first);
        int v = find_set(e.second);
        g[u].pb(v);
        g[v].pb(u);
    }
    int r = find_set(1);
    dfs(r,0,r);
    memset(vis,0,sizeof vis);
    ans = 0;
    dfs(x,0,x);
    cout << (ans + 1)/ 2<< endl;
}