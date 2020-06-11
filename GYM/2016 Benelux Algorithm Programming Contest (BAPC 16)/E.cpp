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
int const MAXN = 2e4 + 9;
vector<pair<int,LL>> g[MAXN];
vector<pair<pair<int,int>,int>> edges;
LL const inf = 1e18;
LL dist[MAXN];
int n,m;
LL x;
void build(LL x){
    for(int i = 0; i <= n; i++)
        g[i].clear();
    for(auto e : edges){
        int u = e.first.first;
        int v = e.first.second;
        LL  w = e.second;
        if(w <= x){
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }
    }
}
LL dij(){
    priority_queue <pair <LL,int> , vector <pair <LL,int> >, greater <pair <LL,int> > >pq;
    for(int i = 0; i <= n; i++)
        dist[i] = inf;
    pq.push ({0,1});
    dist[1] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto cur : g[u]){
            int child = cur.first;
            LL w = cur.second;
            if (dist[child] > dist[u] + w){
                dist[child] = dist[u] + w;
                pq.push( { dist[child], child } );
            }
        }
    }
    return dist[n];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({{u,v},w});
    }
    build(inf);
    LL ssp = dij();
    LL goal = ssp * (100 + x) / 100;
    LL low = 1, hi = 1e9;
    LL ans = 0;
    while(low <= hi){
        LL mid = (low + hi + 1) / 2;
        build(mid);
        LL cur = dij();
        if(cur <= goal){
            ans = mid;
            hi = mid - 1;
        }else low = mid + 1;
    }
    cout << ans << endl;
}