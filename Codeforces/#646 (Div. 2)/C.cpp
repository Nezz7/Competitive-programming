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
int const MAXN = 2000 + 9;
vector<int> g[MAXN];
int sz[MAXN];
string first = "Ayush";
string second = "Ashish";
void dfs(int node, int par){
    sz[node] = 1;
    for(auto child : g[node]){
        if(par == child) continue;
        dfs(child, node);
        sz[node] += sz[child];
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            sz[i] = 0;
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        if(sz(g[x]) <= 1){
            cout << first << endl;
            continue;
        } 
        dfs(x,x);
        bool cond = false;
        for(auto a : g[x]){
            for(auto b : g[x]){
                    if(a == b) continue;
                    int nbr = n - 1 - sz[a] - sz[b];
                    int cur = sz[a] + sz[b] - 1;
                    if((cur & 1) == (nbr & 1)){
                        cond = true;
                    }
            }
        }
        if(cond) cout << first << endl;
        else cout << second << endl;
    }
}