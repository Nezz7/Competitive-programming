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
int mx, s;
vector<int> g[MAXN];
int dep[MAXN];
void dfs(int node, int par){
    if(par != -1){
        dep[node] = dep[par] + 1;
        mx = max(mx, dep[node]);
        if(mx == dep[node])
            s = node;
    }
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child, node);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            dep[i] = 0;
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        mx = 0;
        dfs(a, -1);
        if(dep[b] <= da or da >= db){
            cout << "Alice" << endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            dep[i] = 0;
        }
        mx = 0;
        dfs(s, -1);
        if((mx + 1) / 2 <=  da){
            cout << "Alice" << endl;
        }else if( db >= mx or (db >= (2*(da) + 1)) ){
            cout << "Bob" << endl;
        }else cout << "Alice" << endl;
    }
    
}