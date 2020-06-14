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
int const MAXN = 3e5 + 9;
int a[MAXN],p[MAXN];
map<int,int> dp[MAXN];
vector<int> g[MAXN];
int ans = 0;
void dfs(int node,int par){
    map<int,vector<int>> cur;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child,node);
        for(auto x : dp[child]){
            int idx = __gcd(x.first,a[node]);
            if(idx == 1) continue;
            vector<int> d;
            while(idx > 1){
                int x = p[idx];
                while(idx > 1 && idx % x == 0) idx /= x;
                d.pb(x);
            }
            for(auto p : d){
                cur[p].pb(x.second);
            }
        }
    }
    int idx = a[node];
    while(idx > 1){
        int x = p[idx];
        while(idx > 1 && idx % x == 0) idx /= x;
        dp[node][x] = 1;
    }
    if(a[node] != 1) ans = max(ans,1);
    for(auto x : cur){
        x.second.pb(0);
        sort(rall(x.second));
        dp[node][x.first] = x.second[0] + 1;
        ans = max(ans,x.second[0] + x.second[1] + 1);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[1] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!p[i]){
            for(int j = i; j < MAXN; j += i){
                p[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
   cout << ans << endl;
}