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
int dp1[MAXN];
int dp2[MAXN];
vector<vector<pair<int,int>>> g;
void solve (int node){
    if (dp1[node] != -1) return;
    dp1[node] = 1;
    int mx = 0;
    for (auto cur : g[node]){   
        int child = cur.first;
        int w = cur.second;
        solve (child);
        mx = max(mx,dp1[child]);
        if (dp1[child] == mx)
            dp2[node]= max({w,dp2[child]});
    }
    dp1[node] += mx;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    memset(dp1,-1,sizeof dp1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v,i+1);
    }
    for (int i = 0; i < n; i++){
        solve (i+1);
        //cout<< i + 1 << "  =  "<< dp1[i+1] << " " << dp2[i+1] << endl;
        if (dp1[i+1] == n){
            cout << dp2[i+1] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
  
}