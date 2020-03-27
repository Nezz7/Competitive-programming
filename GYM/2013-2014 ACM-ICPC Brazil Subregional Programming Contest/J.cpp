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
vector<pair<LL,pair<int,int>>> edges;
vector<vector<pair<int,int>>> g;
struct DSU {
    vector<int> root,sz;
    int cc ;
    DSU(int n){
        root.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; i++){
            root[i] = i;
            sz[i] = 1;
        }
        cc = n;
    }
    int find_set (int x){
        if (root[x] == x) return x;
        return root[x] = find_set(root[x]);
    }
    bool union_set(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if ( u == v ) return false;
        if(sz[u] < sz[v]) swap (u,v);
        root[v] = u;
        sz[u] += sz[v];
        cc--;
        return true;
    }
};
struct LCA {
    int timer;
    int l;
    vector<int> tin, tout;
    vector<vector<int>> up,maxi;
    vector<LL> dep;
    LCA(int root, int n){
        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
        l = ceil(log2(n + 1));
        dep.assign(n+1,0);
        up.assign(n+1,vector<int> (l + 1));
        maxi.assign(n+1,vector<int> (l + 1,1e9));
        dfs(root,root,0);
    }
    void dfs(int v, int p, int w){
        tin[v] = ++timer;
        up[v][0] = p;
        maxi[v][0] = w;
        for (int i = 1; i <= l; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
            maxi[v][i] = min(maxi[v][i-1],maxi[up[v][i-1]][i-1]);
        }
        for(auto cur : g[v]){
            int u = cur.first;
            int w = cur.second;
            if ( u == p ) continue;
            dep[u] = dep[v] + 1;
            dfs(u,v,w);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
    int lca (int u, int v){
        if(is_ancestor(u,v)) return u;
        if(is_ancestor(v,u)) return v;
        for (int i = l; i >= 0; i--){
            if(!is_ancestor(up[u][i],v))
                u = up[u][i];
        }
        return up[u][0];
    }
    LL get_best(int v, int d){
        int ret = 1e9;
	    for (int i = l; i >= 0; --i){
            if (d &(1 << i)){
                ret = min(ret, maxi[v][i]);
                v = up[v][i];
            }
	    }
	    return ret;
    }
    int query(int u, int v){
        int l = lca(u,v);
        return min(get_best(u,dep[u] - dep[l]),get_best(v,dep[v] - dep[l]));
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    DSU dsu(n);
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    sort(rall(edges));
    for(auto cur : edges){
        LL w = cur.first;
        int u = cur.second.first;
        int v = cur.second.second;
        if(dsu.union_set(u,v)){
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }
    }
    LCA lca(1,n);
    while(q--){
        int u,v;
        cin >> u >> v;
        cout << lca.query(u,v) << endl;
    }
}