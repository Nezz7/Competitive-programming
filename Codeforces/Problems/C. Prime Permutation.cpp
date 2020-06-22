#include <bits/stdc++.h>
using namespace std;
string s, ans;
vector<vector<int>> adj;
int vis[5000];
int occ[26];
int nbr, n;
void DFS (int node){
    nbr ++;
    vis[node] = 1;
    for (auto child : adj[node]){
        if (!vis[child])
            DFS (child);
    }
}
void build_graph(){
    for (int i = 2 ; i <= n ; i++)
        if (adj[i].size()==0)
            for (int j = 2*i; j <= n ; j+= i){
                adj[i].push_back(j);
                adj[j].push_back(i);
        }
}
void go (int node ,int i){
    ans [node-1] = 'a' + i;
    vis[node] = 1;
    for (auto child : adj[node]){
        if (!vis[child])
            go (child, i);
    }
}
int main (){
    cin >> s;
    n = s.size();
    adj.resize(n+1);
    ans = s;
    for(int i = 0 ; i < n ; i++)
        occ[s[i]-'a']++;
    build_graph();
    priority_queue<pair<int,int>> pq;
    for (int i  = 1; i <= n ;i++)
        if (!vis[i]){
            nbr = 0;
            DFS (i);
            pq.push({nbr,i});
    }
    for (int i = 1 ; i < n ; i++)
        vis[i+1] = 0;
    while (!pq.empty()){
        int sz = pq.top().first;
        int idx = pq.top().second;
         pq . pop();
         bool filled = false;
         for (int i = 0 ; i <26 ;i++){
                if (occ[i] >= sz){
                    occ[i] -= sz;
                    go (idx,i);
                    filled = true;
                    break;
                }
        }
        if (!filled){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES \n";
    cout << ans << "\n";

}
