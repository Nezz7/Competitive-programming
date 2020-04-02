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
int lca;
vector<set<int>> g;
vector<int> leaf;
int n;
void dfs (int node, int par){
    if(node == lca){
        g[node].erase(par);
        return;
    }
    for(auto child : g[node]){
        if (child == par) continue;
        dfs(child,node);
    }
    g[node].clear();
}
void gen(){
    leaf.clear();
    for(int i = 1; i <= n; i++){
        if (sz(g[i]) == 1) leaf.push_back(i);
    }
}
int main(){
    cin >> n;
    g.resize(n+1);
    for (int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i = 0; i < n / 2; i++){
        gen();
        if(sz(leaf) == 0){
            cout << "! " << lca;
            cout.flush();
            return 0;
        }else {
            cout << "? " << leaf[0] << " "<< leaf[1] << endl;
            cout.flush();
            cin >> lca;
            dfs(leaf[0],leaf[0]);
            dfs(leaf[1],leaf[1]);
        }
    }
    cout << "! " << lca;
    cout.flush();

}