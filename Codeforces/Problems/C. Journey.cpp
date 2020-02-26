#include <bits/stdc++.h>
#define f first
#define s second
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
LD dp[MAXN];
vector<vector<int>>  g;
void dfs (int node,int par){
    bool cond = true;
    for (auto child : g[node]){
        if (child == par) continue;
        cond = false;
        dfs(child,node);
        dp[node] += dp[child]/ (LD) (sz(g[node]) - (node != 1) );
    }
    if (!cond){
        dp[node]++; 
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    cout <<setprecision(10)<< dp[1] << endl;
}