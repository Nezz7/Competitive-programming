#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
#define end "\n"
#define LL long long int
using namespace std;
int const MAXN = 1e5 + 9;
int p[MAXN];
bool cond;
int n;
map < pair <int,int>,LL > e;
vector<pair<int,int>> ed;
vector < vector < pair <int,LL > > > adj;
void YES (){
     cout << "YES\n";
        map<pair<int,int>,bool> vis;
        for (int u = 0; u < n; u++){
            for (auto cur : adj[u]){
                int v = cur.first;
                LL w = cur.second;
                if (e.count({u,v})) w = e[{u,v}];
                if (vis[{u,v}]) continue;
                vis[{u,v}] = true;
                vis[{v,u}] = true;
                cout << u << " " << v << " " << w << endl;
            }
        }
        exit(0);
}
void path (int x){
    if (p[x] == x) return;
    if (e.count({x,p[x]})){
        ed.emplace_back(x,p[x]);
    }
    path(p[x]);
}
LL dij(int s, int t) {
    vector <LL> dist (n+1,1e18);
    dist[s] = 0;
    priority_queue <pair <LL,LL> , vector <pair <LL,LL> >, greater <pair <LL,LL> > >pq;
    pq.push (mk(0LL,s));
    p[s] = s;
    while (!pq.empty()){
        int u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (int i = 0;i < adj[u].size();i++){
            int child = adj[u][i].first;
            LL  w = adj[u][i].second;
            if (e.count({u,child})) w = e[{u,child}];
            if (w == -1) continue;
            if (dist[child] > dist[u] + w){
                p[child] = u;
                dist[child] = dist[u] + w;
                pq.push(mk(dist[child],child));
            }
        }
    }
    return dist[t];
}
int main (){
 ios_base::sync_with_stdio(0);
 cin.tie (0);
 LL  m, l, s, t;
 cin >> n >> m >> l >> s >> t;
 adj.resize(n+1);
 cond = false;
 for (int i=0 ; i < m;i++){
      LL u,v,w;
      cin >> u >> v >> w;
      if (w == 0){
        e[{u,v}] = -1;
        e[{v,u}] = -1;
        w = -1;
      }
      adj[u].pb(mk(v,w));
      adj[v].pb(mk(u,w));
    }
    LL dis = dij(s,t);
    if (dis < l){
        cout << "NO";
        return 0;
    }
    if (dis == l){
        for (auto &cur : e)
            cur.second = 1e10;
        YES();
        return 0;
    }
    for (auto &cur : e){
        cur.second = 1;
    }
    dis = dij(s,t);
    if (dis > l){
        cout << "NO";
        return  0;
    }
    LL x = dij(s,t);
    path(t);
    map<pair<int,int>,LL> mp;
    mp  = e;
    for (auto &cur : mp){
        cur.second = 1e10;
    }
    for (auto cur : ed){
        mp[cur] = e[{cur}];
        mp[{cur.second,cur.first}]= e [{cur}];
    }
    e = mp;
    int i = 0;
    while ( x != l){

        int d = l - x;
        while (i < ed.size()){
            e[{ed[i]}]+= d;
            e[{ed[i].second,ed[i].first}]+= d;
            i++;
            break;
        }
        x = dij(s,t);
    }
    YES();
    return 0;
}

