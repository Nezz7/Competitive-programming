#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int n, m;
vector< set <int> > adj;
set <int> unvisited;
void DFS (int node){
    unvisited.erase(node);
    int cur = -1;
    while (true){
        auto it = unvisited.upper_bound(cur);
        if (it == unvisited.end()) break;
        cur = *it;
        if (adj[node].count(cur)) continue;
        DFS(cur);
    }
}
int main (){
    cin >> n >> m ;
    adj.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,  v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int cc = -1;
    for (int i = 1; i <= n; i++)
        unvisited.insert(i);
    for (int i = 1; i <= n; i++)
        if (unvisited.count(i)){
            DFS(i);
            cc++;
            cout << endl;
        }
    cout << cc << endl;
}
