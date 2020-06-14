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
int dep[MAXN];
int marked[MAXN];
vector<vector<int>>g;
vector<int> tree;
LL k ;
void dfs (int node, int par){
    tree.push_back(node);
    dep[node] = tree.size();
    for (auto child : g[node]){
        if(child == par) continue;
        if (!dep[child]){
            dfs(child, node);
        }else{
            if(dep[node] - dep[child] + 1 <= k && dep[node] - dep[child] + 1 >= 2){
                cout << 2 << endl << dep[node] - dep[child] + 1 << endl;
                for (int i = dep[child] - 1;  i < dep[node]; i++){
                    cout << tree[i] << " ";
                }
                exit(0);
            }
        }
    }
      for (auto child : g[node])
          if(!marked[node]) marked[child] = 1;
    tree.pop_back();
  
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m >> k;
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
   dfs(1,1);
   cout << 1 << endl;
   int sz = (k + 1) / 2;
   for (int i = 1; i <= n; i++){
       if (!marked[i] && sz) cout << i << " ", sz--;
   }
 
}