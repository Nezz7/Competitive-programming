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
int const MAXN = 5000 + 9;
vector<vector<int>> g;
vector< pair<int,pair<int,int> > > queries;
int p[MAXN];
void dfs(int node, int par){
    p[node] = par;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
    }
}
vector<int> path;
vector<pair<int,int>> out;
map<pair<int,int>,int> edges;
void get_path(int node){
    path.push_back(node);
    if(p[node] == node) return;
    get_path(p[node]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edges[minmax(u,v)] = 1e6;
        out.emplace_back(minmax(u,v));
    }
    int q;
    cin >> q;
    while(q--){
        int w,a,b;
        cin >> a >> b >> w;
        queries.push_back({w, {a,b}});
    }
    sort(all(queries));
    reverse(all(queries));
    for(auto cur : queries){
        int a = cur.second.first;
        int b = cur.second.second;
        int w = cur.first;
        dfs(a,a);
        path.clear();
        get_path(b);
        int mn = 1e9;
        for(int i = 0; i < sz(path) - 1; i++){
            int u = path[i];
            int v = path[i + 1];
            int & cur = edges[minmax(u,v)];
            if(cur == 1e6) cur = w;
            mn = min(mn,cur);
        }
        if(mn != w){
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto e : out){
        cout << edges[e] << ' ';
    }

}