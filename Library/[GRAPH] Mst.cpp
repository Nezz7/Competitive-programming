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
vector<pair<LL,pair<int,int>>> edges;
vector<vector<pair<int,int>>> g;
struct DSU {
    vector<int> root,size;
    int cc ;
    DSU(int n){
        root.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            root[i] = i;
            size[i] = 1;
        }
        cc = n;
    }
    int find_set (int x){
        if (root[x] == x) return x;
        return root[x] = find_set(root[x]);
    }
    bool union_set(int u, int v){
        u = find_set(u);
        v = find_set(v);
        if ( u == v ) return false;
        if(size[u] < size[v]) swap (u,v);
        root[v] = u;
        size[u] += size[v];
        cc--;
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    DSU dsu(n);
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    sort(all(edges));
    LL mst = 0;
    for(auto cur : edges){
        LL w = cur.first;
        int u = cur.second.first;
        int v = cur.second.second;
        if(dsu.union_set(u,v)){
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
            mst += w;
        }
    }
    cout << mst;
}