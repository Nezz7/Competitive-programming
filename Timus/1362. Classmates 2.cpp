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
 int const MAXN = 2e6 + 9;
 int depth[MAXN];
 vector<vector<int>> g;
 int vn ;
 int ans = 0;
 void dfs (int node, int par){
    for (auto child : g[node]){
        if (child == par) continue;
        dfs (child,node);
        depth[node] = max(depth[child] + 1 , depth[node]);
    }
    depth[node] = max((int)g[node].size() - 1, depth[node]);
 }
 void solve (int node, int par, int cnt){
     ans = max(cnt,ans);
    vector<pair<int,int>> v;
    for (auto child : g[node]){
        if (child == par) continue;
        if (child != vn)
        v.emplace_back(depth[child],child);
        else solve(vn,node,1);
    }
    sort(rall(v));
    for (int i = 0; i < v.size(); i++){
        int child = v[i].second;
        solve (child,node,cnt + i + 1 );
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for (int i = 1; i <= n; i++){
        int u;
        while (cin >> u && u != 0){
            g[i].push_back (u);
        }
    }
    int par;
    cin >> vn;
    for (int i = 1; i <= n ;i ++){
        for (auto child : g[i]) if (child == vn) par = i;
    }
    dfs(1,1);
    solve(par,par,1);
    cout << ans << endl;
 }
