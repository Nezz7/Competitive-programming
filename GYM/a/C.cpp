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
vector<int> g[MAXN];
int d[MAXN],used[MAXN],have[MAXN];
void dfs(int node){
    used[node] = 1;
    for(auto child : g[node]){
        have[child]++;
        if(!used[child] && have[child] >= (d[child] + 1) / 2) dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m, x, s;
    cin >> n >> m >> x >> s;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        d[u]++;
        d[v]++;
    }
    dfs(s);
    if(used[x]) cout << "leave" << endl;
    else cout << "stay" << endl;
}