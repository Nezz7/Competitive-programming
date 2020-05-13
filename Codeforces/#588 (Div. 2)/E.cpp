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
map<LL, LL> dp[MAXN];
vector<vector<int>> g;
LL a[MAXN];
int parent[MAXN];
LL const mod = 1e9 + 7;
LL add (LL a, LL b){
    return (a + b) % mod;
}
void get(int node, int par){
    parent[node] = par;
    for(auto child : g[node]){
        if(child == par) continue;
        get(child,node);
    }
}
LL dfs(int node,int par ,LL gd){
    if(dp[node].count(gd)) return dp[node][gd];
    LL ret = gd;
    for(auto child : g[node]){
        if(child == par) continue;
        ret = add(ret,dfs(child,node,__gcd(gd,a[child])));
    }
    return dp[node][gd] = ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    LL ans = 0;
    get(1,1);
    for(int i = 1; i <= n; i++){
        ans = add(ans,dfs(i,parent[i],a[i]));
    }
    cout << ans;
}