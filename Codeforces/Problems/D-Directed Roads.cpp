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
 int const MOD  = 1e9 + 7;
 vector<vector<int>> adj;
 int vis[MAXN];
 LL p[MAXN];
 int cur =  1;
 vector<LL> cycle;
 void DFS (int node,int start){
    vis[node] = cur++;
    for (auto child : adj[node]){
        if (!vis[child]) DFS(child,start);
        else if (vis[child] >= start)
            cycle.push_back(vis[node] - vis[child] + 1);
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    p[0] = 1;
    adj.resize(n+1);
    for (int i = 1; i < MAXN; i++)
        p[i] = (2LL * p[i - 1]) % MOD;
    for (int i = 0; i < n ; i++){
        int u;
        cin >> u;
        adj[i+1].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) DFS(i,cur);
    LL ans  = 1;
    LL nbr  = 0;
    for (auto cur : cycle){
        nbr +=cur;
        ans = (ans * (p[cur] - 2LL)) % MOD;
    }
    nbr = n - nbr;
    ans = (ans * p[nbr]) % MOD;
    cout << ans << endl;
 }
