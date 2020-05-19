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
int const MAXN = 5000 + 9;
int dp[MAXN];
vector<vector<int>> g;
void dfs(int node, int par){
    int mx = 0;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
        mx = max(mx,dp[child]);
    }
    dp[node] += mx + 1;
}
void dfs2(int node, int par){
    vector<int> v;
    for(auto child : g[node]){
        v.pb(dp[child]);
    }
    sort(all(v));
    if(sz(v) >= 2){
        for(auto child : g[node]){
            if(child == par) continue;
            if(dp[child] ==  v[sz(v) - 1]) dp[child]= max(dp[child],v[sz(v) - 2] + 2);
            else dp[child] = max(v[sz(v) - 1] + 2,dp[child]);
            dfs2(child,node);
        }
    }else {
            for(auto child : g[node]){
            if(child == par) continue;
            dp[child] = max(dp[child], dp[node] - dp[child] + 1);
            dfs2(child,node);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    while(cin >> n){
        g.resize(n + 1);
        for(int i = 1; i <= n; i++){
            dp[i] = 0;
            g[i].clear();
            int x;
            cin >> x;
            for(int j = 0; j < x; j++){
                int v;
                cin >> v;
                g[i].pb(v);
            }
        }
        dfs(1,1);
        dfs2(1,1);
        pair<int,int> ans = {*min_element(dp + 1, dp + n + 1),*max_element(dp + 1, dp + n + 1)};
        cout << "Best Roots : ";
        for(int i = 1; i <= n; i++){
            if(dp[i] == ans.first) cout << i << ' ';
        }
        cout << endl <<"Worst Roots : ";
        for(int i = 1; i <= n; i++){
            if(dp[i] == ans.second) cout << i << ' ';
        }
        cout << endl;
    }
}