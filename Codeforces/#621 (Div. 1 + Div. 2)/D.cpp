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
bool cmp(int a, int b){
    return d1[a] < d1[b];
}
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
    sort(a,a+k,cmp);
    int ans = 0;
    for (int i = 1; i < k; i++){
        int u = a[i - 1];
        int v = a[i];
        ans = max(ans,d1[u] + 1 + dn[v]);
    }
    ans = min(ans,d1[n]);
    cout << ans << endl;
}