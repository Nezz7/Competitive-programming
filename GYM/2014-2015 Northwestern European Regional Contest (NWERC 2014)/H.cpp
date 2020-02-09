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
vector <vector<int>> g;
int val1[MAXN];
int val2[MAXN];
int cur = 2;
void dfs (int node, int par = -1, int val = 0){
    bool isleaf = true;
    int i = 0;
    if (g[node].size() != 1){
        val1[node] = val;
        val2[node] = ++cur;
    } 
    for (auto child : g[node]){
        if (child == par) continue;
        dfs(child,node,val2[node]);
        isleaf = false;
    }
    if (isleaf){
        val1 [node] = val1[par];
        val2 [node] = val2[par];
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i <n; i++){
        int u,v; 
        cin >> u >> v;
        g[u] . push_back(v);
        g[v] . push_back(u);
    }
     int i = 0;
     val1[1] = 1;
     val2[1] = 2;
    for (auto child : g[1]){
        if (child == 1) continue;
        i ^= 1;
        if (i) dfs(child,1,val1[1]);
        else dfs(child,1,val2[1]);
    }
    for (int i = 1; i<= n; i++)
        cout << val1[i] << " " << val2[i] << endl;
}