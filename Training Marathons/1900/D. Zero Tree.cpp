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
LL a[MAXN],mx[MAXN],mn[MAXN];
vector<vector<int>>g;
LL up  = 0, down = 0;
LL ans = 0;
void dfs(int node,int par){
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
        mn[node] = min(mn[node],mn[child]);
        mx[node] = max(mx[node],mx[child]);
    }
    a[node] = a[node] - mn[node] - mx[node];
    if(a[node] > 0){
        mx[node] += a[node];
    }else mn[node] += a[node];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1,1);
    cout << abs(mn[1]) + mx[1] << endl;
}