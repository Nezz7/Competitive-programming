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
int n, l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int dist[MAXN];
void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    dist[v] = dist[p] + 1;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int get (int a, int b){
    int l = lca(a,b);
    return dist[a] + dist[b] - 2 * dist[l];
}
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
int main(){
   // ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    n++;
    adj.resize(n);
    for (int i = 2; i < n; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preprocess(1);
    int q;
    cin >> q;
    while (q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int cycle = get(x,y) + 1;
        int d = get(a,b);
        if (d  == k or (k > d && (k - d) % 2 == 0 )){
            cout << "YES" << endl;
            continue;
        }
        d = get(a,y) + get(b,x) + 1;
        if (d == k or (k > d && (k - d) % 2 == 0 ) or (d < k && ((k -d) % cycle)% 2 == 0) ){
            cout << "YES" << endl;
            continue;
        }
        d = get(a,x) + get(b,y) + 1;
        if (d == k or (k > d && (k - d) % 2 == 0 ) or (d < k && ((k -d) % cycle)% 2 == 0)){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}