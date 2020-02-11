#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5+99;
int p[MAXN],sz[MAXN],cnt[MAXN],vis[MAXN];
map<string,int> id;
vector<vector<pair<int,int>>> adj;
int find_set(int x){
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
}
void union_set (int u,int v){
    u = find_set(u);
    v = find_set(v);
    if( u != v){
        if (sz[u] < sz[v]) swap(v,u);
        p[v] = u;
        sz[u]+=sz[v];
    }
}
void DFS (int node, int s){
    vis[node]= true;
    cnt[node] = s%2;
    for (auto cur : adj[node]){
        int child = cur.first;

        int w = cur.second;
        if (!vis[child]) DFS(child,s+w);
    }
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    int node = 1;
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        p[node] = node;
        sz[node] = 0;
        id[s] = node;
        node++;
    }
    adj.resize(node);
    vector<pair<int,pair<int,int>>>ans;
    for (int i = 0; i < m; i++){
        int t;
        string s1,s2;
        cin >> t >> s1 >> s2;
        ans.push_back({t,{id[s1],id[s2]}});
        int u = find_set(id[s1]);
        int v = find_set(id[s2]);
        if (u != v){
            adj[id[s1]].emplace_back(id[s2],t-1);
            adj[id[s2]].emplace_back(id[s1],t-1);
            union_set(id[s1],id[s2]);
        }
    }
    for (int i = 1; i < node; i++){
        if (!vis[i]) DFS(i,0);
    }
    for (int i = 0; i < m ;i++){
        int t = ans[i].first;
        int u = ans[i].second.first;
        int v = ans[i].second.second;
        if (t-1 ==(cnt[u]+ cnt[v])%2)
            cout << "YES\n";
        else cout << "NO\n";
    }
    while (q--){
        string s1,s2;
        cin >> s1 >> s2;
        int u = find_set(id[s1]);
        int v = find_set(id[s2]);
        if (u != v){
            cout << "3\n";
        }else {
                cout << ((cnt[id[s1]] + cnt[id[s2]])%2) + 1 << "\n";
        }
    }

}
