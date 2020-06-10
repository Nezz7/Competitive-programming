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
int used[MAXN];
vector<int> g[MAXN];
LL cnt = 0;
const LL mod = 1e9 + 7;
LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e & 1)return b * 1ll * fast(b, e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}
void dfs(int node){
    cnt++;
    used[node] = 1;
    for(auto child : g[node]){
        if(!used[child]) dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        if(c == 0){
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    LL ans = fast(n,k);
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cnt = 0;
            dfs(i);
            ans = sub(ans, fast(cnt,k));
        }
    }
    cout << ans << endl;
}