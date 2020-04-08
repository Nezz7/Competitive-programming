#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5 + 9;
LL a[MAXN];
vector <int> bits[65];
vector <set <int> > adj;
int dist[MAXN],par[MAXN];
int ans = INT_MAX;
int n;
void bfs (int node){
    memset(dist,-1,(n+1)*sizeof(dist[0]));
    queue <int> q;
    q.push(node);
    dist[node] = 0;
    par[node] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for(auto child : adj[u]){
            if(dist[child] == -1){
                par[child] = u;
                dist[child] =  dist[u] + 1;
                q.push(child);
            }else if(par[child] != u && par[u] != child)  ans = min(ans,dist[child]  + dist[u] + 1);
        }
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    adj = vector < set<int> > (n+1) ;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = 0; j < 64; j++){
            LL bit = ((a[i]>>j) & 1);
            if (bit) {
                    for (auto cur : bits[j]){
                        adj[i].insert(cur);
                        adj[cur].insert(i);
                    }
                    bits[j].push_back(i);
                    if (bits[j].size() >= 3){
                        cout << 3;
                        return 0;
                    }
            }
 
        }
    }
    for (int i = 0; i < n ; i++){
        bfs(i);
    }
    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans  << "\n";
 
}