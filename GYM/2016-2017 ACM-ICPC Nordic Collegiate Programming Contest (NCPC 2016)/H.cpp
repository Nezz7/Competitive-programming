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
map<int,vector<int>> g;
set<int> vis;
int maxi;
int edges;
LL ans ;
int nbr;
void dfs(int node){
    vis.insert(node);
    nbr++;
    maxi = max(maxi,node);
    edges += sz(g[node]);
    ans += node * 1LL * (sz(g[node]) - 1);
    for(auto child : g[node]) 
        if(!vis.count(child)) dfs(child);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(auto cur : g){
        if(!vis.count(cur.first)){
            maxi = 0;
            edges = 0;
            nbr = 0;
            dfs(cur.first);
            edges /= 2;
            if(edges + 1== nbr) ans += maxi;
        }
    }
    cout << ans << endl;
}