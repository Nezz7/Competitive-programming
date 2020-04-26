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
vector<vector<int>> g;
int mx, x;
int p[MAXN],vis[MAXN];
vector<int > ans;
vector<int > out;
void dfs(int node, int par, int cost){
    cout << " visiting " << node << endl;
    p[node] = par;
    for(auto child : g[node]){
        if(child == par) continue;
        if(cost >= mx){
            x = child;
            mx = cost;
        }
        dfs(child,node,cost + 1);
    }
}
void path(int node){
    vis[node] = 1;
    out.pb(node);
    if(p[node] != node){
        path(p[node]);
    }
}
void dfs1(int node, int par){
    vis[node] = 1;
    ans.pb(node);
    for(auto child : g[node]){
        if(par == child or vis[child]) continue;
        dfs1(child,node);
        ans.pb(node);
    }
}
int main(){
    //ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1,0);
    int start = x;
    dfs(start,start,0);
    int end = x;
    path(end);
    for(auto x : out) cout << x << ' ';
    cout << endl;
    for(auto x : out){
        ans.pb(x);
        for(auto child : g[x]){
            if (!vis[child]){
                dfs1(child,child);
                ans.pb(x);
            }
        }
    }
    cout << sz(ans) - 1 << endl;
    for(auto x : ans) cout << x << ' ';
}