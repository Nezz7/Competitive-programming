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
pair<int,int> q [MAXN];
LL ans [MAXN];
vector<pair<int,pair<int,int>>> edges;
struct DSU {
    vector<int> root,sz;
    int cc ;
    DSU(int n){
        root.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; i++){
            root[i] = i;
            sz[i] = 1;
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
        if(sz[u] < sz[v]) swap (u,v);
        root[v] = u;
        sz[u] += sz[v];
        cc--;
        return true;
    }
};
LL get (LL x){
    x--;
    return x * (x + 1) / 2; 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    for (int i = 0; i < m; i++){
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(q,q + m);    
    sort(all(edges));
    int j = 0;
    LL cur = 0;
    DSU dsu(n+1);
    for(int i = 0; i < m; i++){
        while ( j < sz(edges) && edges[j].first <= q[i].first){
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            cur -= get(dsu.sz[dsu.find_set(u)]);
            cur -= get(dsu.sz[dsu.find_set(v)]);
            dsu.union_set(u,v);
            cur += get(dsu.sz[dsu.find_set(v)]);
            j++;
        }
        ans[q[i].second] = cur;
    }
    for (int i = 0; i < m; i++){
        cout << ans[i] << ' ';
    }
}