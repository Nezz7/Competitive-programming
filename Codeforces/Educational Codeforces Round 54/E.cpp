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
vector < vector<int> > g;
vector < vector < pair < int, int> > > Q;
LL pref[MAXN];
LL ans[MAXN];
LL sum = 0;
void dfs (int node, int par, int dep){
    for(auto cur : Q[node]){
        int d = cur.first;
        int x = cur.second;
        pref[dep] += x;
        if( dep + d + 1 < MAXN) pref[dep + d + 1] -= x;
    }
    sum += pref[dep];
    ans[node] = sum;
    for (auto child : g[node]){
        if ( child == par ) continue;
        dfs(child,node,dep+1);
    }
    sum -= pref[dep];
    for(auto cur : Q[node]){
        int d = cur.first;
        int x = cur.second;
        pref[dep] -= x;
        if( dep + d + 1 < MAXN) pref[dep + d + 1] += x;
    }
} 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    Q.resize(n + 1);
    for (int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--){
        int v,d,x;
        cin >> v >> d >> x;
        Q[v].emplace_back(d,x);
    }
    dfs(1,-1,0);
    for (int i = 1; i <= n; i++){
        cout <<  ans [i] << " ";
    }
}