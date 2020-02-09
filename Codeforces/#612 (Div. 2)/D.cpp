 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 vector<vector<int>> adj;
 int dfs (int node, int p, int mn){
    if (c[node] == 0) a[node] = mn, mn++;
    int m  = 1e9+6;
    for (auto child : adj){
        if (child  == p) continue;
        m = min(m,dfs(child,node,mn));
    }
    if (a[node == -1) a[node] =
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n;i ++){
        int u , c;
        cin >> u >> c[i+1];
        int v = i+1;
        if (u){
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
 }
