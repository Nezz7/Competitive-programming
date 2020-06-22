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
LL const inf = 1e18;
LL dist[MAXN];
vector<int> st[MAXN];
vector<vector<pair<int,int>>>g;
LL get (int node,LL time){
    auto it = lower_bound(all(st[node]),time);
    if (it == st[node].end() or *it != time)
       return time;
    int id = it - st[node].begin();
    int l = id;
    int r = sz(st[node]) - 1;
    int ret = sz(st[node]) - id;
    while (l <= r){
        int mid = (l+r)/2;
        if (st[node][mid] != time + mid - id){
            ret = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    return time + ret;

} 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v;
        LL w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        while (k--){
            int x;
            cin >> x;
            st[i].pb(x);
        }
    }
    for (int i = 1; i <= n; i++) 
        dist[i] = inf;
    priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>> pq;
    dist[1] = get(1,0);
    pq.push({dist[1],1});
    while (!pq.empty()){
        LL d = pq.top().first;
        LL u = pq.top().second;
        pq.pop();
        if (dist[u] < d) continue;
        for (auto cur : g[u]){
            LL w = cur.second;
            int child = cur.first;
            if (child != n){
                LL di = w + dist[u];
                di = get(child,di);
                if (dist[child] > di){
                    dist[child] = di;
                    pq.push({di,child});
                }
            }else {
                if(dist[child] > dist[u]  + w){
                    dist[child] = dist[u]+ w;
                    pq.push({dist[child],child});
                }
            }
        }
    }
    if (dist[n] == inf) cout << -1 << endl;
    else cout << dist[n] << endl;
}