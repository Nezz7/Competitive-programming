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
LL dist[MAXN];
vector<vector<pair<LL,LL>>> g;
int vis[MAXN];
vector<int> out;
int par[MAXN];
void dfs(int node,int p){
    vis[node] = true;
    par[node] = p;
    LL mn = 1e18;
    for(auto child : g[node]){
       mn = min(dist[child.first] + child.second,mn);
    }
     for(auto child : g[node]){
        if(!vis[child.first] && (dist[child.first] + child.second) == mn) continue;
        if(!vis[child.first]) dfs(child.first,node);
    }
}
void get(int x){
    out.pb(x);
    if (par[x] == x){
        return;
    }
    get(par[x]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; i++) dist[i] = 1e18,par[i] = -1;
    for (int i = 0; i < m; i++){
        int u,v;
        LL w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    dist[1] = 0;
    priority_queue <pair <LL,int> , vector <pair <LL,int> >, greater <pair <LL,int> > >pq;
    pq.push ({0,1});
    dist[1] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i = 0; i < g[u].size(); i++){
            int child = g[u][i].first;
            LL w = g[u][i].second;
            if (dist[child] > dist[u] + w){
                dist[child] = dist[u] + w;
                pq.push( { dist[child], child } );
            }
        }
    }
    dfs(0,0);
    if (par[1] == -1) cout << "impossible";
    else {
        get(1);
        cout << sz(out) << " ";
        reverse(all(out));
        for(auto x : out) cout << x << " ";
    }

}