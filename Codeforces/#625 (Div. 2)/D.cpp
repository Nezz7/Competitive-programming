#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int dist[MAXN];
int p[MAXN];
vector<vector<int>> g;
vector<vector<int>> gr;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    gr.resize(n+1);
    for (int i = 0; i < n; i++)
        dist[i+1] = 1e9;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> p[i];
    }
    queue<int> q;
    q.push(p[k-1]);
    dist[p[k-1]] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto child : gr[u]){
            if (dist[child] > dist[u] + 1){
                dist[child] = dist[u] + 1;
                q.push(child);
            }
        }
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < k - 1; i++){
       if(dist[p[i]] == 1 + dist[p[i + 1]]){
            int cnt = 0;
            for (auto child : g[p[i]]){
                cnt += (dist[child]  == dist[p[i]] - 1);
            }
            mx += (cnt > 1);
       }else mx++,mn++;
    }
    cout << mn << " " << mx << endl; 
}