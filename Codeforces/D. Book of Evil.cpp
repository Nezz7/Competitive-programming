 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " = " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int const INF = 1e9;
 int dp[MAXN],dp2[MAXN];
 int c[MAXN];
 vector<vector<int>> g;
 void dfs (int node, int par = -1){
    for (auto child : g[node]){
        if (child == par) continue;
        dfs(child,node);
        dp[node] = max(dp[node], 1 + dp[child]);
    }
 }
 void dfs2 (int node, int par = -1){
    if (c[node]) dp2[node] = max(0,dp2[node]);
    int m1, m2;
    m1 = m2 = - INF;
    for (auto child : g[node]){
        if (child == par) continue;
        if (dp[child] >= m1){
            m2 = m1;
            m1 = dp[child];
        }else if (dp[child]>= m2)  m2 = dp[child];
    }
    for (auto child : g[node]){
        if (child == par) continue;
        int go = m1;
        if (m1 == dp[child]) go = m2;
        dp2[child] = max(dp2[node] + 1, go + 2);
        dfs2(child,node);
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    g.resize (n + 1);
    for (int i = 0; i < m; i++){
        int u;
        cin >> u;
        c[u] = 1;
    }
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int  i = 0; i < n; i++){
        if (!c[i + 1])
        dp2[i + 1] = - INF,dp[i + 1] = - INF;
    }
    dfs(1);
    dfs2(1);
    int ans = 0;
    for (int i = 1; i <= n ; i++){
         ans+= (max(dp[i],dp2[i]) <= k);
    }
    cout << ans;

 }
