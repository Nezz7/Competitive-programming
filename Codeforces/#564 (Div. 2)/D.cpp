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
int const MAXN = 2e5 + 9;
int const mod = 998244353;
LL fact[MAXN];
vector<vector<int>> g;
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL dp[MAXN];
void dfs(int node, int par){
    if(sz(g[node]) == 1 && par != 1) {
        dp[node] = 1;
        return;
    }
    int cnt = 0;
    LL cur = 1;
    dp[node] = 1;
    for(auto child : g[node]){
        if(child == par) continue;
        cnt ++;
        dfs(child,node);
        dp[node] = mul(dp[child],dp[node]);
    }
    dp[node] = mul(dp[node],fact[cnt + (node != 1)]);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] =  mul(fact[i - 1], i);
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    cout << mul(dp[1] , n);
}