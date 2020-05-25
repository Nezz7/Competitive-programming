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
int vis[MAXN];
LL e;
LL cur;
vector<vector<int>> g;
void dfs(int node){
    vis[node] = 1;
    cur ++;
    e += sz(g[node]);
    for(auto child : g[node]){
        if(!vis[child]) dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bool cond = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            e = 0;
            cur = 0;
            dfs(i);
            e /= 2;
            if(cur * (cur - 1) / 2 != e) cond = false;
        }
    }
    if(cond) cout << "YES";
    else cout << "NO";
}