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
 int const MAXN = 205;
 vector<vector<int>> g;
 LL dp[MAXN][MAXN];
 LL a[MAXN];
 int n,k;
 void  dfs (int node, int par){
        dp[node][0] = a[node];
        for(auto child : g[node]){
            if (child == par) continue;
            dfs(child,node);
        }
        for (int dep = 0; dep < MAXN; dep++){
            if (dep == 0){
                for (auto child : g[node]){
                    if(child == par) continue;
                    dp[node][0] += dp[child][k-1];
                }
            }else {
                for (auto x : g[node]){
                    if(x == par) continue;
                    LL cur = dp[x][dep - 1];;
                    for(auto child : g[node]){
                        if(child == par or child == x) continue;
                        cur += dp[child][max(dep - 1, k - dep - 1)];
                    }
                    dp[node][dep] = max(dp[node][dep],cur);
                }
            }
        }
        for (int i = MAXN - 1; i > 0; i--){
            dp[node][i - 1] = max(dp[node][i - 1],dp[node][i]);
        }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    k++;
    g.resize(n+1);
    for (int i = 0; i < n; i++) cin >> a[i+1];
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }
    dfs(1,1);
    cout << dp[1][0] << endl;
 }

