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
vector<int> g[MAXN];
set<int> children[MAXN];
int vis[MAXN], par[MAXN], taken[MAXN];
int nodes = 0;
vector<pair<int,int>> order;
void dfs(int node, int depth){
    order.emplace_back(depth, node);
    nodes++;
    vis[node] = 1;
    for(auto child : g[node]){
        if(!vis[child]){
            children[node].insert(child);
            par[child] = node;
            dfs(child, depth + 1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    n *= 2;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            nodes = 0;
            par[i] = i;
            dfs(i,0);
            if(nodes & 1){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "POSSIBLE" << endl;
    sort(rall(order));
    for(auto cur : order){
        int x = cur.second;
        if(!taken[x]){
            int p = par[x];
            bool cond = false;
            children[p].erase(x);
            while(children[p].size() >= 1 && p != x){
                auto y = *(children[p].begin());
                children[p].erase(y);
                if(!taken[y] && y != x){
                    cout << x << " " << y << " " << p << endl;
                    assert(x != y);
                    taken[y] = 1;
                    cond = true;
                    break;
                }
            }
            if(!taken[p] && x != p && !cond){
                cout << x << " " << p << " " << -1 << endl;
                assert(x != p);
                taken[p] = 1;
            }else {
                if(!cond){
                    int pp = par[p];
                    if(!taken[pp] && x != pp){
                        cout << x << " " << pp << " " << p << endl;
                        assert(x != pp);
                        taken[pp] = 1;
                    }
                }
            }
        }
        taken[x] = 1;
    }
}