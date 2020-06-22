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
int const mod = 998244353 ;
int col[MAXN];
LL p[MAXN];
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
inline LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
bool cond;
vector<vector<int>> g;
void bfs(int node){
    queue<int> q;
    q.push(node);
    col[node] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto child : g[u]){
            if(col[child] == -1){
                col[child] = col[u] ^ 1;
                q.push(child);
            }else if(col[child] == col[u]) cond = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[0] = 1;
    for (int i = 1; i < MAXN; i++){
        p[i] = mul(p[i-1],2);
    }
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        g = vector<vector<int>> (n + 1);
        for(int i = 1; i <= n; i++) col[i] = -1;
        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cond = true;
        for(int i = 1; i <= n; i++){
            if(col[i] == -1) bfs(i);
        }
        if (!cond){
            cout << 0;
            continue;
        }
        int ones = 0;
        for(int i = 1; i <= n; i++){
            ones += (col[i] == 1);
        }
        int zeros = n - ones;
        LL ans = add (p[ones],p[zeros]);
        cout << ans << endl;
    }
}