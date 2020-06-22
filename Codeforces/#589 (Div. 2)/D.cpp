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
 int col[MAXN],vis[MAXN];
 vector<set<int>> adj;
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    while (m--){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    queue<int> q;
    bool cond = true;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto child : adj[u]){
            if (col[child] == col[u]) col[child]++;
            if (!vis[child]){
                 vis[child] = 1;
                 q.push(child);
            }
        }
    }
    set<int> st[3];
    for (int i = 0; i < n; i++){
        if (!vis[i+1]) cond = false;
        if (col[i+1]>=3) cond = false;
        else st[col[i+1]].insert(i+1);
    }
    if (!cond){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < 3; i++){
        if (sz(st[i]) == 0) cond = false;
        for (auto u : st[i]){
            for (auto v : st[(i+1)%3]) if (adj[u].count(v) == 0) cond = false;
        }
        for (auto u : st[i]){
            for (auto v : st[(i+2)%3]) if (adj[u].count(v) == 0) cond = false;
        }
         if (!cond){
            cout << -1;
            return 0;
         }
    }
    for (int i = 0; i < n; i++)
        cout << col[i+1]+1 <<" ";
/*
5 5
1 2
2 3
2 4
1 5
2 5*/
 }
