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
int dp[MAXN][10];
LL depth[MAXN], sz[MAXN];
int n, k;
vector<vector<int>>g;
LL ans = 0;
int sub (int a, int b){
    return ( (a - b) % k + k ) % k;
}
void dfs(int node, int par, int depth){
    dp[node][depth % k] = sz[node] = 1;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child, node, depth + 1);
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                int r = sub(i + j, 2 * depth);
                int needs = sub(k, r);
                ans += (LL) needs * dp[node][i] * dp[child][j];
            }
        }
        for(int i = 0; i < k; i++) dp[node][i] += dp[child][i];
        sz[node] += sz[child];
    }
    ans += sz[node] * (n - sz[node]);
    
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k;
    g.resize(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1, 0);
    cout << ans / k << endl;
    
}