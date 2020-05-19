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
int const MAXN = 200 + 9;
vector<vector<int>> g;
vector<pair<int,int>> edges;
int dp[MAXN][2];
int u, v;
void dfs(int node, int par){
    int mx1 = 0, mx2 = 0;
    int cond = 0;
    for(auto child : g[node]){
        if(child == par) continue;
        if(minmax(child,node) == minmax(u,v)) continue;
        dfs(child,node);
        cond ++;
        if(mx1 <= dp[child][0]){
            mx2 = mx1;
            mx1 = dp[child][0];
        }else if(mx2 < dp[child][0]) 
            mx2 = dp[child][0];
        dp[node][1] = max(dp[child][1],dp[node][1]);
    }
    if(cond >= 2)
    dp[node][1] = max(dp[node][1],mx1 + mx2 + 2);
    if(cond){
        dp[node][0] = mx1 + 1;
        dp[node][1] = max(mx1 + 1,dp[node][1]);
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
        edges.emplace_back(minmax(u,v));
    }
    int ans = 0;
    for(auto e : edges){
        memset(dp,0,sizeof(dp));
        u = e.first;
        v = e.second;
        dfs(u,u);
        dfs(v,v);
        ans =  max(ans,dp[u][1] * dp[v][1]);
    }
    cout << ans  << endl;
}