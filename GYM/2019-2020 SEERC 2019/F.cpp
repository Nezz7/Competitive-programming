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
int dp[MAXN];
vector<int> g[MAXN];
string first = "Alice", second = "Bob";
void dfs(int node, int par){
    LL sum = 0;
    for(auto child : g[node]){
        if(child == par) continue;
        dfs(child, node);
        sum += dp[child];
    }
    if(sum == 0) dp[node] = 1;
    else dp[node] = sum - 1;
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    } 
    dfs(1,1);
    if(dp[1] == 0){
        cout << second << endl;
    } else  cout << first << endl;
}