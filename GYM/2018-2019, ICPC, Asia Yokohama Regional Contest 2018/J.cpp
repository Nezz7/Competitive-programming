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
int const MAXN = 2e5 + 9;
vector<vector<int>>g;
int col[MAXN];
int id[MAXN];
set<pair<int,int>> node[MAXN];
LL ans[MAXN];
int nbr = 0;
struct LCA {
    int timer;
    int l;
    vector<int> tin, tout;
    vector<vector<int>> up;
    vector<LL> dist;
    LCA(int root, int n){
        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
        l = ceil(log2(n + 1));
        dist.assign(n+1,0);
        up.assign(n+1,vector<int> (l + 1));
        dfs(root,root);
    }
    void dfs(int v, int p){
        id[v] = ++nbr;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for(auto cur : g[v]){
            int u = cur;
            if ( u == p ) continue;
            dist[u] = dist[v] + 1;
            dfs(u,v);
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
    LL get_dist(int u, int v){
        return dist[u] + dist[v] - 2 *dist[lca(u,v)];
    }
};
void add(int c, int x,LCA & lca){
    if(sz(node[c]) == 0){
        node[c].insert({id[x],x});
        return;
    }  
    int oldlca = lca.lca(node[c].rbegin()->second,node[c].begin()->second);
    node[c].insert({id[x],x});
    int newlca = lca.lca(node[c].rbegin()->second,node[c].begin()->second);
    // lca change 
    if(newlca != oldlca){
        ans[c] += lca.get_dist(oldlca,x);
        return;
    }
    // lca dont change
    int u;
    int distA , distB;
    auto it = node[c].upper_bound({id[x],x});
    if (it == node[c].end()) distA = 1e9;
    else {
        u = it->second;
        distA = lca.get_dist(x,lca.lca(u,x));
    }
    it = node[c].lower_bound({id[x],x});
    if (it == node[c].begin()){
        distB = 1e9;
    }else {
        it --;
        u = it->second;
        distB = lca.get_dist(x,lca.lca(u,x));
    }
    ans[c] += min(distB,distA);
}


void del(int c, int x,LCA & lca){
    if(sz(node[c]) == 1){
        node[c].erase({id[x],x});
        ans[c] = 0;
        return;
    }
    int oldlca = lca.lca(node[c].rbegin()->second,node[c].begin()->second);
    node[c].erase({id[x],x});
    int newlca = lca.lca(node[c].rbegin()->second,node[c].begin()->second);
    // lca change 
    if(newlca != oldlca){
        ans[c] -= lca.get_dist(newlca,x);
        return;
    }
    // lca dont change
    int u;
    int distA , distB;
    auto it = node[c].upper_bound({id[x],x});
    if (it == node[c].end()) distA = 1e9;
    else {
        u = it->second;
        distA = lca.get_dist(x,lca.lca(u,x));
    }
    it = node[c].lower_bound({id[x],x});
    if (it == node[c].begin()){
        distB = 1e9;
    }else {
        it --;
        u = it->second;
        distB = lca.get_dist(x,lca.lca(u,x));
    }
    ans[c] -= min(distB,distA);
    node[c].erase({id[x],x});
}
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    LCA lca(1,n);
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    for (int i = 1; i <= n; i++){
        add(col[i],i,lca);
    }

    int q;
    cin >> q;
    while (q--){
        char type;
        cin >> type;
        if (type == 'Q'){
            int c;
            cin >> c;
            if(sz(node[c]) == 0) cout << -1 << endl;
            else cout << ans[c] << endl;
        }else {
            int c,x;
            cin >> x >> c;
            // del
            del(col[x],x,lca);
            // add
            col[x] = c;
            add(col[x],x,lca);
        }
    }
}