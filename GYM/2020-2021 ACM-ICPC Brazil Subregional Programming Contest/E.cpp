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
vector<int> g[MAXN], query[MAXN];
int a[MAXN], ans[MAXN], up[MAXN][30];
int l;
struct BIT {
    #define T int
    vector<T> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) 
            ret += bit[r];
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void dfs(int v, int p){
    up[v][0] = p;
    for (int i = 1; i <= l; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : g[v]){
        dfs(u,v);
    }
}

int find_owner(int u, int r){
    for (int i = l; i >= 0; i--){
        if(a[up[u][i]] <= r)
            u = up[u][i];
    }
    return u ;
}
BIT tree(MAXN);
void dfs2(int node){
    for(auto cur : query[node]){
        tree.add(cur, +1);
    }
    ans[node] = tree.sum(a[node]);
    for(auto child : g[node]){
        dfs2(child);
    }
    for(auto cur : query[node]){
        tree.add(cur, -1);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    l = ceil(log2(n + 1));
    for(int i = 1; i <= n; i++){
        int boss;
        cin >> a[i] >> boss;
        if(i != 1)
            g[boss].push_back(i);
    }
    dfs(1, 1);
    for(int i = 0; i < m; i++){
        int o, l, r;
        cin >> o >> l >> r;
        o = find_owner(o, r);
        query[o].push_back(l);
    }
    dfs2(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}