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
struct BIT {
    #define T int
    vector<T> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) 
            ret += bit[r];
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
vector<vector<int>> g;
int cur = 0, sz, root = 0;
int depth[MAXN], id[MAXN];

void dfs(int node, int par){
    depth[node] = 1 + depth[par];
    sz = max(depth[node], sz);
    id[node] = cur;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child, node);
    }
}
vector<BIT> tree;
void update(int v, int x, int d){
    int idx = id[v];
    if(depth[v] - d > 0) tree[idx].add(depth[v] - d, x);
    else{
        // add to all other chains
        int d1 = d - depth[v];
        tree[0].add(d1 + 1, - x);
        tree[0].add(0,x);
        tree[idx].add(d1 + 1, x);
    }
    int sz = tree[idx].n - 1;
    tree[idx].add(min(depth[v] + d + 1,sz), -x);
}
int get(int x){
    if(x == 1) return tree[0].sum(0,0);
    int idx = id[x];
    return tree[idx].sum(0,depth[x]) + tree[0].sum(0,depth[x]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, q;
    cin >> n >> q;
    g.resize(n + 1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cur = 1;
    tree.pb(BIT(1e5 + 2));
    for(auto child : g[1]){
        dfs(child,1);
        cur++;
        tree.pb(BIT(sz + 5));
    }
    while(q--){
        int t;
        cin >> t;
        if(!t){
            int v, x, d;
            cin >> v >> x >> d;
            update(v, x, d);
        }else{
            int x;
            cin >> x;
            cout << get(x) << endl;
        }
    }
}