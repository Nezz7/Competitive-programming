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
int d1[MAXN],dn[MAXN],a[MAXN];
vector<vector<int>> adj;
void bfs (int s, int * dist){
    queue <int>  q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto child : adj[u]){
            if (dist[child] == -1){
                dist[child] = 1 + dist[u];
                q.push(child);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    adj.resize(n+1);
    for (int i = 0; i < k; i++){
        cin >> a[i];
    }
    memset(dn,-1,sizeof dn);
    memset(d1,-1,sizeof d1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,d1);
    bfs(n,dn);
    int mx = a[0];
    for (int i = 0; i < k ; i++){
        if (d1[mx] < d1[a[i]]) mx = a[i];
    }
    LL cur = 0;
    for (int i = 0; i < k; i++){
        if (a[i] == mx) continue;
        cur = max((LL)  1LL + min(dn[a[i]] + d1[mx],d1[a[i]] + dn[mx]),cur);
    }

    int mx2 = a[0];
    for (int i = 0; i < k; i++){
        if (dn[mx2] < dn[a[i]] ) mx2 = a[i];
    }

    for (int i = 0; i < k; i++){
        if (a[i] == mx2) continue;
        cur = max((LL) 1LL + min(dn[a[i]] + d1[mx2],d1[a[i]] + dn[mx2]),cur);
    }
    LL ans = min((LL)d1[n],cur);
    cout << ans << endl;
}