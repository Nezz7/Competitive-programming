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
vector<int> g[MAXN];
int dist[MAXN][MAXN];
void bfs(int s){
    dist[s][s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(dist[s][v] > dist[s][u] + 1){
                dist[s][v] = dist[s][u] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    freopen("ysys.in","r",stdin);
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            dist[i][j] = 1e9;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
        bfs(i + 1);
    int d0, n0;
    cin >> d0 >> n0;
    int cur = n0;
    int tim = 0;
    int win = 1e9;
    for(int i = 1; i < q; i++){
        int d, x;
        cin >> d >> x;
        tim += dist[x][cur];
        if(tim > d){
            cout << 0;
            return 0;
        }
        cur = x;
        win = min(win,d - tim);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dist[n0][i] <= min(win,d0)) ans++;
    }
    cout << ans << endl;
}