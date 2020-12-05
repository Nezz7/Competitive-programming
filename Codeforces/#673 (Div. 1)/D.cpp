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
int const MAXN = 1e6 + 9;
int from[MAXN], to[MAXN], a[MAXN], type[MAXN], id[MAXN];
int n;
bool removed[MAXN];
int tim, tin[MAXN], tout[MAXN];
vector<int> g[MAXN];
struct DSU {
    vector<int> root,size;
    int cc ;
    DSU(int n){
        root.resize(n + 1);
        for (int i = 0; i <= n; i++){
            root[i] = i;
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
        n++;
        root[u] = n;
        root[v] = n;
        root[n] = n;
        g[n].push_back(u);
        g[n].push_back(v);
        return true;
    }
};

pair<int,int> tree[4*MAXN];
struct SegTree{
    #define T pair<int,int> // Type
    const T MYZERO = {0,0}; //ZERO OF F
    int n;
    SegTree(int sz){
        n = sz;
    }
    T merge(T a, T b){ // DEFINE
        return  max(a,b);
    }
    T query (int l, int r){
        return query (1, 0, n -1, l, r) ;
     }
    T query (int node, int start, int end, int l, int r){
        if (r < start or end < l) return MYZERO;
        if (l <= start  && end <= r) return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(2*node,start,mid,l,r);
        T p2 = query(2*node+1,mid+1,end,l,r);
        return merge(p1,p2);
    }
    void update (int node, int start, int end, int idx, T val){
        if (start == end){
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node, start, mid, idx, val);
        else 
            update(2*node + 1, mid + 1, end,idx,val);
        tree[node] = merge(tree[2*node], tree[2*node + 1]);    
    }
    void update (int idx, T val){
        update(1, 0, n - 1, idx, val);
    }
};

void dfs(int node){
    tin[node] = ++tim;
    for(auto child : g[node]){
        dfs(child);
    }
    tout[node] = tim;
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int m ,q;
    cin >> n >> m >> q;
    DSU dsu(MAXN);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> from[i] >> to[i];
    }
    for(int i = 1; i <= q; i++){
        cin >> type[i] >> id[i];
        if(type[i] == 2){
            removed[id[i]] = true;
        }
    }
    for(int i = 1; i <= m; i++){
        if(!removed[i]){
            dsu.union_set(from[i], to[i]);
        }
    }
    for(int i = q; i >= 1; i--){
        if(type[i] == 2){
            dsu.union_set(from[id[i]], to[id[i]]);
        }else {
            id[i] = dsu.find_set(id[i]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(dsu.find_set(i) == i){
            dfs(i);
        }
    }

    SegTree tree(n + 1);
    for(int i = 1; i <= n; i++){
        tree.update(tin[i],{a[i],tin[i]});
    }
    for(int i = 1; i <= q; i++){
        if(type[i] == 1){
            auto ret = tree.query(tin[id[i]], tout[id[i]]);
            cout << ret.first << endl;
            ret.first = 0;
            tree.update(ret.second, ret);
        }
    }

}