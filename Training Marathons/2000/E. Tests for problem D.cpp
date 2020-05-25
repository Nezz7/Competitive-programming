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
vector<int> out[MAXN];
int cur;
void dfs(int node, int par){
    for(auto child : g[node]){
        if(child == par) continue;
        out[child].pb(++cur);
    }
    out[node].pb(++cur);
    for(int i = sz(g[node]) - 1; i >= 0; i--){
        int child = g[node][i];
        if(child == par) continue;
        dfs(child,node);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cur = 1;
    out[1].pb(cur);
    dfs(1,1);
    for(int i = 1; i <= n; i++){
        for(auto x : out[i]) cout << x << ' ';
        cout << endl;
    }
}