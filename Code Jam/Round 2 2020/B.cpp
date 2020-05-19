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
vector<vector<int>> g;
pair<int,int> x[MAXN];
int dist[MAXN];
int ans[MAXN];
int par[MAXN];
map<pair<int,int>,int> w;
vector<int> p;
vector<pair<int,int>> edges;
void path(int node){
    p.push_back(node);
    if(par[node] == node) return;
    path(par[node]);
}
int n,m;
void dij (int e, int len){
    priority_queue <pair <int,int> , vector <pair <int,int> >, greater <pair <int,int> > >pq;
    pq.push ({0,1});
     for(int i = 1; i <= n; i++){
        dist[i] = 1e9;
    }
    dist[1] = 0;
    par[1] = 1;
    while (!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        if(e == u) break;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto child : g[u]){
            int cur = w[minmax(u,child)];
            if (dist[child] > dist[u] + cur){
                par[child] = u;
                dist[child] = dist[u]+ cur;
                pq.push( { dist[child], child } );
            }
        }
    }
    p.clear();
    path(e);
    reverse(all(p));
    bool first = true;
    LL cur = 0;
    for(int i = 0; i < sz(p) - 1; i++){
        if(w[minmax(p[i],p[i + 1])] == 1e6 && first){
            first = false;
            int nbr = sz(p) - 1 - i - 1;
            w[minmax(p[i],p[i + 1])] = len - cur - nbr;
        }else if(w[minmax(p[i],p[i + 1])] == 1e6) w[minmax(p[i],p[i + 1])]= 1;
        cur += w[minmax(p[i],p[i + 1])];
    }
}
void solve(int t){
    edges.clear();
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++){
        g[i].clear();
        dist[i] = 1e9;
    }
    for(int i = 2; i <= n; i++){
        cin >> x[i].first;
        x[i].first *= -1;
        x[i].second = i;
    }
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        w[minmax(u,v)] = 1e6;
        edges.emplace_back(minmax(u,v));
    }
    sort(x + 2, x + n + 1);
    for(int i =2 ; i <= n; i++){
        dij(x[i].second,x[i].first);
    }
    
    cout << "Case #"<< t <<": ";
    for(auto e : edges) cout << w[e] << ' ';
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
   for(int t = 1; t <= T; t++){
       solve(t);
   }
}