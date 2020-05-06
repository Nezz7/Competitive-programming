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
bool cycle = false;
int vis[MAXN];
vector<vector<int>> g[2];
int dp[2][MAXN];
void dfs(int node){
    vis[node] = 1;
    for(auto child : g[0][node]){
        if(!vis[child]) dfs(child);
        else if(vis[child] == 1) cycle  = true;
    }
    vis[node] = 2;
}
int solve(int idx, int node){
    int & ret = dp[idx][node];
    if(~ ret) return ret;
    ret = node;
    for(auto child : g[idx][node])
        ret = min(ret,solve(idx,child));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g[0].resize(n + 1);
    g[1].resize(n + 1);
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[0][u].pb(v);
        g[1][v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    if(cycle){
        cout << -1;
        return 0;
    }
    string ans = "";
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int mini = min(solve(0,i),solve(1,i));
        if(mini == i){
            cnt++;
            ans+="A";
        }else ans += "E";
    }
    cout << cnt << endl;
    cout << ans ;
}