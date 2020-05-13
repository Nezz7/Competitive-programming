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
LL dp[MAXN];
int sz[MAXN];
vector<vector<int>> g;
int n;
LL ans  = 0;
void dfs(int node, int par){
    sz[node] = 1;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
        sz[node] += sz[child];
        dp[node] += dp[child];
    }
    dp[node] += sz[node];
}
void dfs2(int node, int par){
     for(auto child : g[node]){
        if(child == par) continue;
        dp[child] = dp[node] + n - 2 * sz[child];
        dfs2(child,node);
    }
    ans = max(dp[node],ans);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    g.resize(n + 1);
    for(int i = 0; i < n - 1; ++i){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,-1);
    dfs2(1,-1);
    cout << ans << endl;
}