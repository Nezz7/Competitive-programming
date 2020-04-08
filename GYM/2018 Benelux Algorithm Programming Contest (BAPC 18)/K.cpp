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
int const MAXN = 2e6 + 9;
vector<vector<int>> g;
vector<int> leaves;
void dfs(int node,int par){
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
    }
    if(sz(g[node]) == 1) leaves.pb(node);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, h;
    cin >> n >> h;
    g.resize(n);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    cout << (sz(leaves) + 1)/2 << endl;
    int len = (sz(leaves)/2);
    for (int i = 0; i <(sz(leaves) + 1)/2; i++)
        cout << leaves[i] << " " << leaves[ i + len] << endl;

}