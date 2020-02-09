#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN=3e5+9;
vector<pair<int,pair<int,int>>>edges;
LL dp[MAXN];
int last[MAXN];
int main (){
    int n,m;
    cin>>n>>m;
    while (m--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    sort (edges.begin(),edges.end());
    LL ans = 0;

    for (auto e : edges){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (w > last[u]){
        if (dp[v] < dp[u] + 1);
            last[v] = w,dp[v] = dp[u] + 1;
        }
        ans = max(ans,dp[v]);
    }
    cout << ans <<  "\n";


}
