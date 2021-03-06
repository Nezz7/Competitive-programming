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
vector<vector<pair<int,int>>>g;
int n;
int w[MAXN],sz[MAXN];
LD p[MAXN];
void dfs (int node, int par){
    sz[node] = 1;
    for (auto cur : g[node]){
        int child = cur.first;
        int id = cur.second;
        if (child == par) continue;
        dfs(child,node);
        sz[node] += sz[child];
        p[id] = ((sz[child] * 1.0L * (n - sz[child])) * 2.0L)/  ( (n - 1)* 1.0L* (n));

    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    g.resize(n+1);
    for (int i = 1; i < n; i++){
        int u,v,c;
        cin >> u >> v >> c;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
        w[i] = c;
    }
    int q;
    cin >> q;
    cout <<fixed << setprecision(10);
    LD ans = 0;
    dfs(1,1);
    for (int i = 1; i < n; i++){
        ans+= w[i] * p[i];
    }
    while (q--){
        int id, c;
        cin >> id >> c;
        ans -= w[id] * p[id];
        w[id] = c;
        ans += w[id] * p[id];
        cout << 3*ans << endl;
    }
}