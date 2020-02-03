#include <bits/stdc++.h>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie(0); cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        int n, m;
        cin >> n >> m;
        bool vis[n+3];
        memset(vis,false,sizeof vis);
        vector<vector<int>>adj(n+1);
        for (int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        set<int> a,b;
        queue<int> q;
        q.push(1);
        a.insert(1);
        while(!q.empty()){
            int u = q.front();
            int team = 0;
            if (a.count(u)) team = 1;
            else team = 2;
            vis[u] = true;
            q.pop();
            for (auto child : adj[u]){
                if (a.count (child) or b.count(child)) continue;
                if (!vis[child]){
                    q.push(child);
                    if (team == 1) b.insert(child);
                    else a.insert(child);
                }
            }
        }
        if (a.size() >  b.size()){
            a = b;
        }
        cout << a.size() << "\n";
        for (auto cur : a){
            cout << cur << " ";
        }
        cout << "\n";
    }

}
