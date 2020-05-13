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
int dp[MAXN],police[MAXN];
map<pair<int,int>,int> edges;
vector<vector<int>> g;
set<int> out;
int vis[MAXN];
void dfs(int node,int par){
    if(!police[node]) dp[node] = MAXN;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
        dp[node] = min(dp[node], 1 + dp[child]);
    }
}
void dfs2(int node,int par){
    for(auto child : g[node]){
        if(child == par) continue;
        dp[child] = min(dp[child],1 + dp[node]);
        dfs2(child,node);
    }
}
void get(int node,int par){
    vis[node] = true;
    for(auto child : g[node]){
        if(child == par) continue;
        if(!vis[child] && dp[child] == dp[node] + 1) get(child,node);
        else out.insert(edges[minmax(child,node)]);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k,d;
    cin >> n >> k >> d;
    g.resize(n + 1);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        police[x] = 1;
    }
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edges[minmax(u,v)] = i;
    }
    dfs(1,1);
    dfs2(1,1);
    for(int i = 1; i <= n; i++) 
        if(!vis[i] && police[i]) get(i,i);
    cout << sz(out) << endl;
    for(auto x : out) cout << x << ' ';
    cout << endl;

}