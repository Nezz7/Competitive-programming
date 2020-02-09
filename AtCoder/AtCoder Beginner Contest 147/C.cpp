#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e6+5;
vector<vector<int>> adj;
vector<set<int>> un;
int vis[20];
vector<int> v;
void DFS (int node){
    vis[node] = 1;
    v.push_back(node);
    for (auto child : adj[node]){
        if (!vis[child]) DFS(child);
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    adj.resize(n+5);
    un.resize(n+5);
    int ans = 0;
    for (int i = 0; i < n;i++){
      int x,a,b;
        cin >> x;
        for (int j = 0; j < x; j++){
            cin >> a >> b;
            if (b == 1){
                adj[i+1].push_back(a);
            }else {
                un[i+1].insert(a);
            }
        }
    }
    int mx = (1<<n);
    for (int i = 1; i < mx ; i++){
        v.clear();
        memset(vis,false,sizeof vis);
        for (int j = 0; j <= 15; j++){
            int bit = ((i) &(1 << j))>>j;
            if (bit){
                if (!vis[j+1])
                DFS(j+1);
            }
        }
        bool cond = true;
        for (auto cur : v){
            for (auto x : un[cur])
                if (vis[x]) cond = false;
        }
        if (cond){

                ans = max((int)v.size(),ans);
                }
    }
    cout << ans << endl;

}
