#include <bits/stdc++.h>
#define LL long long int
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
using namespace std;
int const MAXN = 5009;
vector<vector<LL>>adj;
LL dp[MAXN][MAXN];
int n,m,k;
LL a[MAXN], b[MAXN], c[MAXN], l[MAXN];
LL solve (int i, LL w){
    if (w < a[i]) return -1e9;
    if (i == n) return 0;
    LL  & ret = dp[i][w];
    if (ret != -1) return ret;
    w += b[i];
    ret = solve(i+1,w);
    LL k = 0;
    LL cost = 0;
    for (auto child : adj[i]){
        k++;
        LL s = solve(i+1,w-k);
        cost += child;
        ret = max(ret,cost + s);
    }
    return ret;
}
int main (){
    memset(dp,-1,sizeof dp);
    memset(l,-1,sizeof l);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    adj.resize(n+1);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    while (m--){
        LL u, v;
        cin >> u >> v;
        u--,v--;
        l[v] = max(l[v],u);
    }
    for (int i = 0; i < n; i++){
        if (l[i] != -1)
            adj[l[i]].push_back(c[i]);
        else adj[i].push_back(c[i]);
    }
    for (auto &cur : adj) sort(rall(cur));
    LL ans = solve (0,k);
    cout << max(ans,-1LL);
}
