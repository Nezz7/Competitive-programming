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
int c[MAXN];
bool dp[MAXN][3];
vector < vector<int> > g;
int get(int x){
    return (x == 1);
}
void dfs (int node, int par, int x){
    int cnt = c[par] + x;
    if (cnt <= 0) 
    if ((c[node] && c[node] != cnt) or (cnt <= 0) ){
        dp[node][get(x)] = false;
        cout << "visiting node  " << node << " " << par << " " << cnt << ' ';
        cout << "false" << endl;
        return;
    }
    c[node] = cnt;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node,+1);
        if(!dp[child][1]) dfs(child,node,-1);
        if(!dp[child][0]) {dp[node][get(x)] = false; 
        cout << "visiting node " << node << " " << par << " " << cnt << ' ';
        cout << "false" << endl;
        return;}
    }
    cout << "visiting node " << node << " " << par << " " << cnt << ' ';
        cout <<  "true" << endl;
    dp[node][get(x)] = true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int k;
    cin >> k;
    int root;
    for(int i = 0; i < k; i++){
        int u, x;
        root = u;
        cin >> u >> x;
        c[u] = x;
    }
    dfs(root,root,0);
    cout << root << endl;
    if(dp[root][0]){
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << c[i] << ' ';
    }else cout << "NO" << endl;
}