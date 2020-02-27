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
int const MAXN = 1005;
LL const inf = 1e18;
LL dist[MAXN][MAXN];
LL t[MAXN],c[MAXN];
vector<vector<pair<LL,LL>>>g;
void dij (int s){
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> pq;
    dist[s][s] = 0;
    pq.push({0,s});
    while (!pq.empty()){
        LL d = pq.top().first;
        LL u = pq.top().second;
        pq.pop();
        if (d > dist[s][u] ) continue;
        for (auto cur : g[u]){
            int child = cur.first;
            LL w = cur.second;
            if (dist[s][child] > d + w){
                dist[s][child] = d + w;
                pq.push({dist[s][child],child});
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    int x,y;
    cin >> n >> m;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = inf;
    g.resize(n+1);
    for (int i = 0; i < m ;i ++){
        int u,v;
        LL w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i = 1; i <= n; i++){
        cin >>  t[i] >> c[i];
    }
    for (int i = 1; i <= n; i++)
        dij(i);
    for (int i = 0; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j && dist[i][j] <= t[i]){
                g[i].emplace_back(j,c[i]);
            }
            dist[i][j] = inf;
        }
    }
    dij(x);
    if (dist[x][y] == inf) 
        cout<< -1 << endl;
    else 
        cout << dist[x][y] << endl;
}