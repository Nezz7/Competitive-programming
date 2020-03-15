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
int vis[MAXN];
int col[MAXN];
set<int> go[2];
vector<int> ans;
vector<vector<int>>g;
stack<int> st;
LL d ;
int cur = 1;
void dfs (int node,int start){
    st.push(node);
    vis[node] = cur++;
    for (auto child : g[node]){
        if (!vis[child]) dfs(child,start);
        else  if ((vis[node] - vis[child] + 1) >= d){
            cerr << "h";
                while (!st.empty()){
                    cerr << st.top();
                    ans.pb(st.top());
                    st.pop();
                }
            }
    }
    st.pop();
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    d = sqrt(n);
    if ((d *d ) != n ) d++;
    cout << d;
    memset(col,-1,sizeof col);
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    if (sz(ans)){
        cerr << "h";
        cout <<"2\n"<< ans.size() << endl;
        for (auto cur : ans) cout << cur << " ";
        return 0;
    }
    cout << 1 << endl;
    queue<int> q;
    q.push(1);
    col[1] = 1;
    go[1].insert(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v  : g[u]){
            if (col[v] ==  -1){
                 col[v] = 1 - col[u];
                 go[col[v]] .insert(v);
                 q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (auto cur : g[i]){
            if (col[i] == col[cur] && go[col[i]].count(i) && go[col[i]].count(cur) ){
                 go[col[i]] .erase(cur);
            }
        }
    }
    int i = 0;
    if (go[1].size()>= d){
        for (auto cur : go[1]){
            if (i < d){
                i++;
                cout << cur  << " ";
            }
        }
        return 0;
    }
    i = 0;
    if (go[2].size()>= d){
        for (auto cur : go[2]){
            if (i < d){
                i++;
                cout << cur  << " ";
            }
        }
        return 0;
    }
    return 1;

}