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
LL dp[MAXN],col[MAXN];
vector<vector<int>> g;
void dfs (int node, int par){
    if (col[node] == 1) dp[node] = 1;
    else dp[node] = -1;
    for (auto child : g[node]){
        if (child == par) continue;
        dfs(child,node);
        if (dp[child] > 0) dp[node] += dp[child];
    }

}
void dfs2(int node, int par){
    for (auto child : g[node]){
        if (child == par) continue;
        if (dp[node] > dp[child] && dp[child] > 0) dp[child] += (dp[node] - dp[child]);
        else if (dp[node] > dp[child] && dp[node] > 0) dp[child] += dp[node];
        dfs2(child,node);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for (int i = 0; i < n; i++)
        cin >> col[i+1];
    for (int i = 0; i < n -1 ; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    dfs2(1,1);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    
}