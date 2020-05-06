
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
int vis[MAXN];
int linked[MAXN];
vector<int> top;
set<int> ans;
vector<set<int>> g;
void dfs(int node){
    vis[node] = true;
    for(auto child : g[node]){
        if(!vis[child])
            dfs(child);
    }
    top.pb(node);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,t;
    cin >> n >> m >> t;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[v].insert(u);
    }
    vis[t] = 1;
    for(auto child : g[t]){
        if(!vis[child]) dfs(child);
    }
    reverse(all(top));
    if(sz(top) && g[t].count(top[0]){
        linked[top[0]] = 1;
        ans.insert(top[0]);
    } 
    for(int i = 1; i < sz(top); i++){
        if(g[top[i - 1]].count(top[i]) && linked[top[i-1]]){
            linked[top[i]] = 1;
            if(g[top[i-1]])
        }else if(g[t].count(top[i])){
            linked[top[i]] = 1;
            ans.insert(top[i]);
        }
    }
    cout << sz(ans) << endl;
    for(auto cur : ans) cout << cur <<  endl;
}