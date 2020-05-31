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
int const MAXN = 2e5 + 9;
vector<int> g[MAXN];
int sz[MAXN],b[MAXN], c[MAXN];
LL a[MAXN]; 
LL ans = 0;
pair<int,int> dfs(int node, int par){
    a[node] = min(a[node], a[par]);
    int x = 0, y = 0;
    if(b[node] != c[node]){
        if(b[node]) x++;
        else y++;
    }
    for(auto child : g[node]){
        if(child == par) continue;
        auto cur = dfs(child, node);
        x += cur.first;
        y += cur.second;
    }
    int mn = min(x,y);
    x -= mn;
    y -= mn;
    ans +=  mn * 2LL * a[node];
    return {x,y};
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int x = 0, y = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
        x += c[i];
        y += b[i];
    }
    if(x != y){
        cout << -1 << endl;
        return 0;
    }
     for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
    dfs(1,1);
    cout << ans << endl;
}