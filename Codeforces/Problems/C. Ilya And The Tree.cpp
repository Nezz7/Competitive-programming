#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5+9;
vector<vector<int>> adj;
int ans[MAXN], a[MAXN];
map<pair<int,pair<int,int>>,int> dp;
void DFS (int node, int p , int val, int l){
    pair<int,pair<int,int>> cur = {node,{val,l}};
    if (dp[cur]) return;
    ans[node] = max(ans[node],__gcd(val,a[node]));
    if (l)
        ans[node] = max(ans[node],val);
    for (auto child : adj[node]){
        if (child == p) continue;
        if (l)
            DFS(child,node,val,0);
        DFS(child,node,__gcd(val,a[node]),l);
    }
    dp[cur]= ans[node];
}
int main (){
    int n;
    cin >> n;
    adj.resize(n+1);
    for (int i = 0; i < n; i++)
        cin >> a[i+1];
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,0,0,1);
    for (int i = 1; i <= n ;i++)
        cout <<ans[i]<< " ";
}
