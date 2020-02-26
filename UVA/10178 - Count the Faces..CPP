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
int const MAXN = 1000;
int cycle;
int p[MAXN],sz[MAXN];
int find_set (int x){
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
}
bool union_set (int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if (sz[u] < sz[v]) swap(u,v);
        p[v] = u;
        sz[u] += sz[v];
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    
    int n,m;
    while (cin >> n >> m){
        for (int i = 0; i < MAXN; i++)
            p[i] = i, sz[i] = 1;
        cycle = 1;
        for (int i = 0; i < m; i++){
            char u, v;
            cin >> u >> v;
            cycle += !union_set(u,v);
        }
        cout << cycle << endl;
        
    }
}