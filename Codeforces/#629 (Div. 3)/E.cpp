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
vector<vector<int>> g;
struct LCA {
    int timer;
    int l;
    vector<int> tin, tout;
    vector<int> up;
    vector<LL> dep;
    LCA(int root, int n){
        tin.resize(n + 1);
        tout.resize(n + 1);
        timer = 0;
        l = ceil(log2(n + 1));
        dep.assign(n+1,0);
        up.assign(n+1,0);
        dfs(root,root);
    }
    void dfs(int v, int p){
        tin[v] = ++timer;
        up[v] = p;
        for(auto cur : g[v]){
            int u = cur;
            if ( u == p ) continue;
            dep[u] = dep[v] + 1;
            dfs(u,v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }
    bool query(int u, int x){
        return is_ancestor(u,x) or is_ancestor(up[u],x);
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,q;
    cin >> n >> q;
    g.resize(n+1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    LCA lca(1,n);
    while(q--){
        int k;
        cin >> k;
        vector<int> v;
        int depth = -1;
        int u = -1;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            v.pb(x);
            if(lca.dep[x] > depth){
                depth = lca.dep[x];
                u = x;
            }
        }
        bool cond = true;
        for (auto x : v){
            cond &= lca.query(x,u);
        }
        if(cond){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
}