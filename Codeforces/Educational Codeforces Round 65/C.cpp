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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu (n + 1);
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        int u;
        if(k){
            cin >> u;
            for(int j = 0; j < k - 1; j++){
                int v;
                cin >> v;
                dsu.union_set(u,v);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int x = dsu.find_set(i);
        cout << dsu.sz[x] << " ";
    }
}