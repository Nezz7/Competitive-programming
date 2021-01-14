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
int col[MAXN];
vector<int> g[MAXN];

void bfs(int node, int c){
    queue<int> q;
    q.push(node);
    col[node] = 1;
    for(auto child : g[node]){
        col[child] = 2;
        q.push(child);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto child : g[u]){
            if(col[child] == 0){
                col[child] = 1;
                for(auto v : g[child]){
                    if(col[v] == 0){
                        col[v] = 2;
                        q.push(v);
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) g[i].clear(), col[i] = 0;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs(1,1);
        vector<int> out;
        bool cond = true;
        for(int i = 1; i <= n; i++){
            if(col[i] == 1) out.push_back(i);
            if(col[i] == 0) cond = false;
        }
        if(cond){
            cout << "YES" << endl;
            cout << out.size() << endl;
            for(auto x : out) cout << x << " ";
            cout << endl;
        }else cout << "NO" << endl;
    }
}