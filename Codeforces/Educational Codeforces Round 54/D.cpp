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
int const MAXN = 2e6 + 9;
vector<vector<pair<int,int>>> g;
int par[MAXN],vis[MAXN];
vector<vector<pair<int,int>>> gr;
map<pair<int,int>,int> edges;
vector<int> ans;
int n,m,k;
void dfs(int node,int par = -1){
    if(par != -1 && ans.size() < k){
        ans.push_back(edges[{par,node}]);
    }
    for(auto child : gr[node]){
        if(child.second == par) continue;
        dfs(child.second,node);
    }
}
void gen(int x){
    if(vis[x]) return;
    vis[x] = 1;
    int p = par[x];
    int id = edges[{x,p}];
    gr[x].emplace_back(id,p);
    gr[p].emplace_back(id,x);
    gen(p);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m >> k;
    g.clear();
    g.resize(n + 1);
    gr.resize(n + 1);
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
        edges[{u,v}] = i + 1;
        edges[{v,u}] = i + 1;
    }
    vector <long long int> dist (n+1,1e18);
    priority_queue <pair <int,int> , vector <pair <int,int> >, greater <pair <int,int> > >pq;
    dist[1]= 0;
    par[1] = 1;
    pq.push ({0,1});
    while (!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i = 0; i < g[u].size();i++){
            int child = g[u][i].first;
            int w = g[u][i].second;
            if (dist[child] > dist[u] + w){
                dist[child] = dist[u] + w;
                par[child] = u;
                pq.push( { dist[child], child } );
            }
        }
    }
    vis[1] = 1;
    for (int i = 1; i <= n; i++){
        gen(i);
    }
    dfs(1);
    cout << ans.size() << endl;
    for(auto cur : ans){
        cout << cur << " ";
    }    

}