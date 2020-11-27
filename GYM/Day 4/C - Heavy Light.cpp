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
int const block = 700;
map<pair<int,int>,int> edges;
vector<pair<int,int>> g[MAXN];
int d[MAXN], tot[MAXN], cur[MAXN], state[MAXN], a[MAXN];
vector<int> heavy;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        if(a[i] != a[i + 1]){
            edges[minmax(a[i],a[i + 1])]++;
        }
    }
    g[0].emplace_back(a[0], 1);
    g[a[0]].emplace_back(0, 1);
    g[0].emplace_back(a[n - 1], 1);
    g[a[n - 1]].emplace_back(0, 1);
    for(auto e : edges){
        int u = e.first.first;
        int v = e.first.second;
        int w = e.second;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
        d[u]++;
        d[v]++;
    }
    for(int i = 1; i <= k; i++){
        if(d[i] > block){
            heavy.push_back(i);
            for(auto u : g[i]){
                int w = u.second;
                tot[i] += w;
            }
            cur[i] = tot[i];
        }
    }
    int ans = 0;
    while(q--){
        int node;
        cin >> node;
        state[node] = 1 - state[node];
        if(d[node] <= block){
            for(auto u: g[node]){
                int v = u.first;
                int w = u.second;
                if(state[v] == state[node]) ans -= w;
                else ans += w;
                if(d[v] > block){
                    if(state[v] == state[node]){
                        cur[v] += w;
                    }else cur[v] -= w;
                }
            }
        }else {
            ans += cur[node]; 
            cur[node] = tot[node] - cur[node];
            ans -= cur[node];
            for(auto u : heavy)
                if(edges.count(minmax(u,node))){
                    int w = edges[minmax(u, node)];
                    if(state[u] == state[node]) cur[u] += w;
                    else cur[u] -= w;
                }
            
        }
        cout << ans / 2 << endl;
    }
}