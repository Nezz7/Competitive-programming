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
int sz[MAXN];
vector<vector<pair<int,int>>> g;
vector<pair<pair<int,int>,LL>> edges;
void dfs(int node,int par){
    sz[node] = 1;
    for(auto cur : g[node]){
        int child = cur.first;
        if (child == par) continue;
        dfs(child,node);
        sz[node] += sz[child];
    }
}
int main(){
   ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int n = 2 * k;
        g.resize(n + 1);
        edges.clear();
        for(int i = 0; i < n + 1; i++) g[i].clear();
        for(int i = 0; i < n - 1; i++){
            int u, v;
            LL w;
            cin >> u >> v >> w;
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
            edges.push_back({{u,v},w});
        }
        dfs(1,1);
        LL mx = 0, mn = 0;
        for(auto e : edges){
            int u = e.first.first;
            int v = e.first.second;
            LL w = e.second;
            LL y = min(sz[u],sz[v]);
            LL x = n - y;
            mx += min(x,y)* w;
            if((y & 1) && (x & 1)) mn += w;
        }
        cout << mn << ' ' << mx << endl;
    }
}