
 using namespace std;
 int const MAXN = 2e6 + 9;
 int const MOD = 1e9 + 7;
 LL dp[MAXN][2],c[MAXN];
 vector<vector<int>> g;
 void dfs (int u, int par = -1){
    dp[u][0] = 1;
    dp[u][1] = 0;
    for (auto v : g[u]){
        if ( v == par ) continue;
        dfs(v,u);
        dp[u][1] *= dp[v][0];
        dp[u][1] %= MOD;
        dp[u][1] += dp[u][0] * dp[v][1];
        dp[u][1] %= MOD;
        dp[u][0] *= dp[v][0];
        dp[u][0] %= MOD;
    }
      if (c[u] == 1){
        dp[u][1] = dp[u][0];
     }else dp[u][0] += dp[u][1];
        dp[u][1] %= MOD;
        dp[u][0] %= MOD;
 }

 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for (int i = 0; i < n - 1; i++){
        int p;
        cin >> p;
        g[i+1].push_back(p);
        g[p].push_back(i+1);
    }
    for(int i = 0; i < n; i++)
        cin >> c[i];
    dfs(0);
    cout << dp[0][1];
 }
