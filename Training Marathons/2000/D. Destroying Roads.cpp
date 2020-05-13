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
int const MAXN = 3000 + 9;
int dist[MAXN][MAXN];
vector<vector<int>> g;
void bfs(int start,int dist[]){
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto child : g[u]){
            if(dist[child] > dist[u] + 1){
                dist[child] = dist[u] + 1;
                q.push(child);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++) 
            dist[j][i] = 1e9;
    }
    for(int i = 0; i < m ; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int s1,t1,l1;
    cin >> s1 >> t1 >> l1;
    int s2,t2,l2;
    cin >> s2 >> t2 >> l2;
    for(int i = 1; i <= n; i++)
        bfs(i,dist[i]);
    if(dist[s1][t1] > l1 or dist[s2][t2] > l2){
        cout << -1;
        return 0;
    }
    int cnt = dist[s1][t1] + dist[s2][t2]; 
    for(int it = 0; it < 2; it++){
        swap(s1,t1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int p1 = dist[s1][i] + dist[i][j] + dist[j][t1];
                int p2 = dist[s2][i] + dist[i][j] + dist[j][t2];
                if(p1 <= l1 && p2 <= l2){
                    cnt = min(cnt,p1 + p2 - dist[i][j]);
                }
            }
        }
    }
    cout << m - cnt << endl;
}