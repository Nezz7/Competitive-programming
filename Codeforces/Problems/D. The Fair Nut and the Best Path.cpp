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
LL a[MAXN];
LL dp[MAXN];
LL ans = -1e18;
vector<vector<pair<int,LL>>> g;
void dfs(int node, int par){
    dp[node] = a[node];
    LL mx1 = -1e18;
    LL mx2 = -1e18;
    LL child1 = -1;
    LL child2 = -1;
    for (auto cur : g[node]){
        int child = cur.first;
        LL w = cur.second;
        if(child == par) continue;
        dfs(child,node);
        dp[node]  = max(dp[node],dp[child]  - w + a[node]);
        if(dp[child] - w >= mx1){
            mx2 = mx1;
            child2 = child1;
            mx1 = dp[child] - w;
            child1 = child;
        }else if(dp[child] - w> mx2){
            mx2 = dp[child] - w;
            child2 = child;
        }
    }
    if (child2 == -1) return;
    for (auto cur : g[node]){
        int child = cur.first;
        LL w = cur.second;
        if(child == par) continue;
        if (child != child1){
            dp[child] = max(dp[child],mx1 + dp[child] - w  + a[node]);
        }else {
            dp[child] = max(dp[child],mx2 + dp[child] - w + a[node]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++){
        int u,v;
        LL w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs(1,1);
    for(int i = 1; i <= n; i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
}