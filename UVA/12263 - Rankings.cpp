#include <bits/stdc++.h>
using namespace std;
bool cycle;
vector<int> ans;
vector<set<int>> adj;
int const MAXN = 500;
bool vis[MAXN];
bool done[MAXN];
void DFS (int node){
    vis[node] = true;
    done[node] = true;
    for (auto child : adj[node]){
        if (!vis[child]) DFS(child);
        else if (done[child]) cycle = true;
    }
    done [node]= false;
    ans.push_back(node);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin .tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ans.clear();
        cycle = false;
        adj.clear();
        memset(vis,false,sizeof vis);
        memset(done,false,sizeof done);
        int n ;
        cin >> n;
        adj.resize(n+1);
        int a[n];
        for (int i  = 0; i < n; i++)
            cin >> a[i];
        reverse(a,a+n);
        for (int i  = 0; i < n; i++){
            for (int j = i+1; j <n ; j++)
                adj[a[i]].insert(a[j]);
        }
        int m;
        cin >> m;
        for (int i = 0; i < m ;i++){
            int u , v;
            cin >> u >> v;
            if (adj[u].count(v)){
                adj[u].erase(v);
                adj[v].insert(u);
            }else {
                adj[v].erase(u);
                adj[u].insert(v);
            }
        }
        for (int i = 1; i <= n;i++)
            if (!vis[i]) DFS(i);
         if (cycle) cout << "IMPOSSIBLE";
        else
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if (i + 1 != ans.size()) cout << " ";
        }
        if (T)
        cout << "\n";
        }
    }

