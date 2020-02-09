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
 int const MAXN = 2e5 + 9;
 int n,m,k;
 vector<vector<int>> g;
 vector<int> out;
 int c[MAXN],sum[MAXN];
 void dfs (int u, int par = -1){
    for (auto v : g[u]){
        if (v == par) continue;
        dfs(v,u);
        sum[u] +=  sum[v];
    }
 }
 int findNode (int u, int par = -1){
    int mx = -1;
    int ret = -1;
    for (auto v : g[u]){
        if (v == par) continue;
        ret = max (ret, findNode(v,u));
        mx = max(mx,sum[v]);
    }
    mx = max(mx, 2 * k - sum[u]);
    if (mx <= k ) ret = u;
    return ret;
 }
 void go (int u, int par = -1 , int s = -1){
        if (c[u])
            out.push_back(u);
        for (auto v : g[u])
            if (par != v) go(v,u,s);
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    g.resize(n+1);
    for (int i = 1; i < n ; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < 2 * k; i++){
        int u;
        cin >> u;
        c[u] = sum[u] = 1;
    }
    dfs(1);
    int x = findNode(1);
    for (auto u : g[x]){
        go (u,x);
    }
    if (c[x]) out.push_back(x);
    cout << "1 \n" << x << endl;
    for (int i = 0 ; i < k; i++){
         cout << out[i] << " " << out[i+k] << " " << x << endl;
    }


 }
/*9 4
1 2
2 3
2 4
1 5
5 6
7 1
7 8
7 9
2 3 4 5 6 7 8 9*/
