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
 LL const inf =  1e15;
 int a[MAXN];
 vector<vector<int>> g;
 LL dp[MAXN][4];
 void dfs (int node, int par = -1){
    dp[node][1] = a[node];
    LL m1 = -inf, m2 = -inf;
    int cnt = 0;
    for (auto child : g[node]){
        if (child == par) continue;
        dfs(child,node);
        cnt++;
        dp[node][1] += dp[child][1];
        dp[node][0] = max({dp[node][0],dp[child][1],dp[child][0]});
        LL x = max(dp[child][1],dp[child][0]);
        if (x >= m1){
            m2 = m1;
            m1 = x;
        }else if (x > m2) m2 = x;
        dp[node][2] = max(dp[child][2],dp[node][2]);
    }
    if (cnt >= 2) dp[node][2] = max(m1 + m2,dp[node][2]);
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i],dp[i][0] = - inf,dp[i][2] = -inf;
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    if (dp[1][2] <= -inf) cout << "Impossible" << endl;
    else cout << dp[1][2] << endl;
 }

