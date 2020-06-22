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
vector<vector<int>> g;
int depth [MAXN];
set<int> st;
int mx = -1;
int mn = 0;
bool even = false, odd = false;
void dfs (int node, int par){
    if (node != par) depth[node] = 1 + depth[par];
    mx++;
    if(sz(g[node]) == 1){
        if(!st.count(par)){
            st.insert(par);
        }else mx--;
        if(depth[node] & 1) odd = true;
        else even = true;
    }
    for(auto child : g[node]){
        if (child == par) continue;
        dfs(child,node);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    if(n == 2){
        cout << 1 << ' ' << 1;
        return 0;
    }
    int root = 1;
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        if(sz(g[u]) > 1) root = u;
        if(sz(g[v]) > 1) root = v;
    }
    dfs(root,root);
    if (odd && even) mn = 3;
    else mn = 1;
    cout << mn << ' ' << mx << endl;
}