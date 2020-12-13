#include "bits/stdc++.h"
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 1e9;
const int N = 1e5;

int n,m;
int label[N+2];
vector<int> adj[N+2];
int seen[N+2];
int seen2[N+2];
int color[N+2];

void explore(int u, int& nb_nodes, int c, bool& is_bipartite){
    seen[u] = true;
    color[u] = c;
    ++nb_nodes;

    for(int v: adj[u]){
        if(!seen[v]) explore(v, nb_nodes, 1 + 2 - c, is_bipartite);
        else if(color[v] == c) is_bipartite = false;
    }
}

void explore2(int u, int cur_depth, int& nb_even_depth, int& nb_odd_depth){
    seen2[u] = true;
    if(cur_depth % 2 == 0) ++nb_even_depth;
    else ++nb_odd_depth;

    for(int v: adj[u]){
        if(!seen2[v]) explore2(v, cur_depth + 1, nb_even_depth, nb_odd_depth);
    }
}

LL contribution(LL x){ return (x*(x-1))/2; }

int main(){ FAST
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        cin >> label[i];
    }
    for(int i=1; i<=m; ++i){
        int u,v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    LL ans = 0;
    for(int u=1; u<=n; ++u){
        if(!seen[u]){
            int nb_nodes = 0;
            bool is_bipartite = true;
            explore(u, nb_nodes, 1, is_bipartite);
            
            if(!is_bipartite) ans += contribution(nb_nodes);
            else{
                int nb_even_depth = 0;
                int nb_odd_depth = 0;
                explore2(u, 1, nb_even_depth, nb_odd_depth);

                ans += contribution(nb_even_depth);
                ans += contribution(nb_odd_depth);
            }
        }
    }

    cout << ans << ln;
}