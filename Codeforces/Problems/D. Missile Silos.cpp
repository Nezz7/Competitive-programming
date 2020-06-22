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
LL const inf = 1e18;
LL dist[MAXN];
vector<vector<pair<LL,LL>>> g;
vector<pair<pair<int,int>,int>> edges;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,s;
    cin >> n >> m >> s;
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v;
        LL w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
        edges.push_back({{u,v},w});
    }
    LL l;
    cin >> l;
    for (int i = 0; i <= n; i++) dist[i] = inf;
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> pq;
    pq.push({0,s});
    dist[s] = 0;
    while (!pq.empty()){
        LL d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto cur : g[u]){
            int child = cur.first;
            LL w = cur.second;
            if (dist[child] > w + dist[u]){
                dist[child] = w + dist[u];
                pq.push({dist[child],child});
            }
        }
    }
    LL ans = 0;
    LL cnt = 0;
    set<pair<pair<int,int>,LL>> st;
    for (int i = 1; i <= n; i++){
        if (dist[i] == l) ans++;
    }
    for (auto cur : edges){
        int u = cur.first.first;
        int v = cur.first.second;
        int w = cur.second;
        if (dist[u] < l && dist[v] < l){
            int x = l - dist[u];
            int y = l - dist[v];
            int xx = w - x;
            int yy = w - y;
            LL d1 = min(l,xx + dist[v]);
            LL d2 = min(l,yy + dist[u]);
            if (x < w && y < w){
               if (xx == y && d1 == l) {
                   cnt++;
                continue;
                }
            }
            if (x < w && d1 == l)  cnt++;
            if (y < w && d2 == l)  cnt++;
            continue;
        }
        if (dist[u] < l && l - dist[u] < w){
            int x = l - dist[u];
            int xx = w - x;
            LL d1 = min(l,xx + dist[v]);
            cnt += (d1 == l);
        }
        if (dist[v] < l && l - dist[v] < w){
            int y = l - dist[v];
            int yy = w - y;
            LL d2 = min(l,yy + dist[u]);
            cnt += (d2 == l);
        }
    }
   
    ans += cnt ;
    cout << ans << endl;
}