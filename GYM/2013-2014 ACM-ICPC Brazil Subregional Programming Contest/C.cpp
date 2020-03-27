#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 1e3 + 9;
vector<vector<int>> g;
int d[MAXN],id[MAXN],k[MAXN],vis[MAXN];
int dfs(int node, int cond){
    vis[node] = 1;
    int ret = 1e9;
    if(!cond) ret = k[node];
    for(auto child : g[node]){
        if(!vis[child])
        ret = min(ret,dfs(child,0));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    g.resize(n+1);
    for(int i = 1; i <= n; i++)
        id[i] = i;
    for(int i = 1; i <= n; i++)
        cin >> k[i];
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[v].pb(u);
        d[v]++;
    }

    while(q--){
        char type;
        cin >> type;
        if(type == 'P'){
            int x;
            cin >> x;
            memset(vis,0,(n+2)*sizeof(vis[0]));
            int ret = dfs(id[x],1);
            if(ret != 1e9){
                cout << ret << endl;
            }else cout << "*" << endl;
        }else {
            int u,v;
            cin >> u >> v;
            swap(id[u],id[v]);
            swap(k[id[u]],k[id[v]]);
        }
    }
}