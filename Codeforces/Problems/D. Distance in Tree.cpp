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
 int const MAXN = 5e4 + 9;
 int k;
 vector<vector<int>> g;
 LL dp[MAXN][509];
 void dfs (int node, int par = -1){
     dp[node][0] = 1;
     for (auto child : g[node]){
         if (child == par) continue;
         dfs(child,node);
         for (int i = 0; i < k; i++)
            dp[node][i + 1]+= dp[child][i];
     }
     for (auto child : g[node]){
        if (child == par) continue;
        dp[node][k] += dp[child][k];
        for (int i  = 0; i < k ;i ++)
            if (i == 0) dp[node][k] += dp[child][k - i - 1] * dp[node][i];
            else dp[node][k] += dp[child][k - i - 1] * (dp[node][i] - dp[child][i - 1]);
     }

 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n >> k;
    g.resize(n+1);
    for (int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,-1);
    cout << dp[1][k] / 2;
 }
