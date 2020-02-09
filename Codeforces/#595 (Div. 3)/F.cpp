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
 int const MAXN = 500;
 vector<vector<int>> g;
 LL dp[MAXN][MAXN];
 LL a[MAXN];
 int n,k;
 void  dfs (int node, int par = -1){
        dp[node][0] = a[node];
        for (auto child : g[node]){
             if (child == par) continue;
             dfs(child,node);
             dp[node][0] += dp[child][k];
        }
        for (int i  = 1; i < n; i++){
            for (auto child : g[node]){
                if (child == par) continue;
                LL cur = dp[node][i-1];
                for (auto to : g[node]){
                    if (to == child or to == par) continue;
                    cur += dp[to][max(i - 1, k - i)];
                }
                dp[node][i] = max(dp[node][i],cur);
            }
        }
        for (int i = n - 1; i >= 0; --i){
            dp[node][i] = max(dp[node][i],dp[node][i+1]);
        }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    g.resize(n+1);
    for (int i = 0; i < n; i++) cin >> a[i+1];
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }
     dfs(1);
     cout << dp[1][0] << endl;
 }
