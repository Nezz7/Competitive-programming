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
int const MAXN = 100 + 9;
int  g[MAXN][MAXN];
int d[MAXN];
int n,m;
int vis[MAXN];
vector<pair<int,int>> edges;
void dfs(int node, int par){
    vis[node] = 1;
    for (int i = 1; i <= n; i++){
        if(vis[i] or g[node][i] ) continue;
        dfs(i,node);
    }
    if(par != -1 && (d[node] & 1)){
        d[node]++;
        d[par]++;
        edges.emplace_back(minmax(par,node));
    }
}
void DFS(int node){
    vis[node] = 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i] && g[node][i]) DFS(i);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
        d[u]++;
        d[v]++;
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i,-1);
    for(int i = 1; i <= n; i++){
        if(d[i] & 1){       
            cout << -1;
            return 0;
        }
    }
    for(auto cur : edges){
        int u = cur.first;
        int v = cur.second;
        g[u][v] = g[v][u] = 2;
    }

    memset(vis,0,sizeof(vis));
    vector<int> v;
    int cnt = 0;
    for(int i = 1; i <= n; i++)if(!vis[i]) DFS(i),v.push_back(i);
    if (sz(v) == 2){
        int u = v[0];
        int vv = v[1];
        int x = -1;
        int y = -1;
        for (int i = 1; i <= n; i++){
            if (i == u or !g[u][i]) continue;
            x = i;
            break;
        }
        for (int i = 1; i <= n; i++){
            if (i == vv or !g[vv][i]) continue;
            y = i;
            break;
        }
        if ( x != -1 && y != -1){
            edges.emplace_back(minmax(u,vv));
            edges.emplace_back(minmax(x,vv));
            edges.emplace_back(minmax(u,y));
            edges.emplace_back(minmax(x,y));
        }else {
            if (y == -1) swap(x,y),swap(u,vv);
            memset(vis,0,sizeof(vis));
            y = -1;
            DFS(vv);
            vv = -1;
            bool cond = false;
            for(int i = 1; i <= n && !cond; i++){
               for(int j = 1; j <= n && !cond; j++){
                   if (i == j or !vis[i] or !vis[j] or g[i][j] == 1) continue;
                   if(g[i][j] == 2) cnt--;
                   vv = i;
                   y = j;
                   cond = true;
               }
            }
            if ( y == -1) {
                cout << -1;
                return 0;
            }
            if(g[vv][y] == 0){
                edges.emplace_back(minmax(vv,y));
            }
            if(g[vv][y] == 2) g[y][vv]= g[vv][y] = -1;
            edges.emplace_back(minmax(u,y));
            edges.emplace_back(minmax(u,vv));
        }
    }
    if(sz(v) > 2){
        for (int i = 0; i < sz(v) - 1; i++){
            edges.emplace_back(minmax(v[i],v[i+1]));
        }
        edges.emplace_back(minmax(v[0],v[sz(v) - 1]));
    }
    cout << sz(edges) + cnt << endl;
    for (auto cur : edges){
        int u = cur.first;
        int v = cur.second;
        if(g[u][v] == -1) continue;
        cout << u << ' ' << v << endl;
    }
}