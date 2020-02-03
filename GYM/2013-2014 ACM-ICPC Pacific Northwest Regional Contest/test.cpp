#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using uint = unsigned int;
const int N =4e5+5, MOD = 99824435;
int n, k;
vector<vector<pair<int, ll>>> adj;
ll dp[10005][22];
int sz[N];
void dfs(int u, int p){
  fill(dp[u],dp[u] + k+1, 0);
  sz[u] = 1;
  for(auto e : adj[u])if(e.first != p){
    dfs(e.first, u);
    sz[u] += sz[e.first];
    for(int i = k; i >= 0; --i)
      for(int j = 0; j <= i; j++)
        dp[u][i] = max(dp[u][i], dp[u][i-j] + dp[e.first][j] + e.second * (j >= sz[e.first]));
  }
}
int main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
  int t;cin>>t;
  while(t--){
    cin >> n >> k;
    ll tot = 0;
    adj.assign(n,vector<pair<int, ll>>());
    for(int i = 1, u, v, w; i < n; i++){
      cin >> u >> v >> w; w+=w;
      tot += w;
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    }
    ll ans = 0;
    for(int i = 0; i <= k; i++){
      dfs(i, i);
      ans = max(ans, dp[i][k]);
    }
    cout << tot - ans << '\n';
  }

  return 0;
}
/*1
7 2
0 1 1
1 2 1
2 3 6
3 4 10
5 6 3
5 2 10000*/
