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
int const MAXN = 2e6 + 9;
LL n, m, k;
int a[MAXN];
map<pair<int,int>, vector<pair<int,int>> > edges;
stack<pair<int,int>> st;
int root[MAXN], sz[MAXN], d[MAXN];

int find_set(int x){return (x == root[x]) ? x : find_set(root[x]);}

int get(int x) {return (x == root[x]) ? 0 : get(root[x]) ^ d[x];} 

int bad[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        root[i] = i;
        sz[i] = 1;
        d[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges[minmax(a[u], a[v])].emplace_back(u, v);
    }
    LL cnt = 0;
    for(int i = 1; i <= k; i++){
        bool bipartite = true;
        for(auto e : edges[{i,i}]){
            int u = find_set(e.first);
            int v = find_set(e.second);
            if(u == v){
                if(get(u) == get(v)){
                    bipartite = false;
                }
                continue;
            }
            if(sz[u] < sz[v]){
                swap(u,v);
            }
            sz[u] += sz[v];
            root[v] = u;
            d[v] = get(e.first) ^ get(e.second) ^ 1; 
        }
        bad[i] = bipartite == false; 
        if(!bad[i]) cnt++;
    }
    LL ans = (cnt * (cnt - 1)) / 2;
    for(auto x : edges){
        auto cur = x.first;
        auto es = x.second;
        if(bad[cur.second] or bad[cur.first] or cur.first == cur.second){
            continue;
        }

        bool bipartite = true;
        for(auto e : es){
            int a = e.first, b = e.second;
            int u = find_set(a);
            int v = find_set(b);
            if(u == v){
                if(get(a) == get(b)){
                    bipartite = false;
                }
                continue;
            }
            if(sz[u] < sz[v]) swap(u, v);
            st.push({u,v});
            sz[u] += sz[v];
            root[v] = u;
            d[v] = (get(a) ^ get(b) ^ 1);

        }
        if(!bipartite) ans--;
        while(!st.empty()){
            int u = st.top().first;
            int v = st.top().second;
            st.pop();
            sz[u] -= sz[v];
            root[v] = v;
            d[v] = 0;
        }
    }
    cout << ans << endl;
}