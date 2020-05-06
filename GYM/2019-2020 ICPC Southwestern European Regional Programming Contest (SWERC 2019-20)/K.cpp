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
 int sz, ss, id;
 vector < set <int> > g, gr;
 vector<set<int>> adj;
 vector<bool> used;
 vector<int> order;
 set<int> have;
 vector<vector<int>> component;
 int scc[MAXN],dp[MAXN];
int n,m,t;
 void dfs1 (int v) {
        used[v] = true;
        for (auto child : g[v])
            if (!used[ child])
                dfs1 (child);
        order.push_back (v);
 }
void dfs2 (int v) {
        used[v] = true;
        component[id].push_back (v);
        for (auto child : gr[v])
            if (!used[child]){
                dfs2 (child);
            }
}
 int solve(int node){
    if(node == scc[t]) return 1;
    int & ret = dp[node];
    if(ret != -1) return ret;
    ret = 0;
    for(auto child : adj[node]){
        ret += solve(child);
    }
    return ret;
 }
 int main(){
    memset(dp,-1,sizeof (dp));
    cin >> n >> m >> t;
    g.resize(n+2);
    gr.resize(n+2);
    adj.resize(n+2);
    component.resize(n+2);
    used.assign (n+2,false);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(a == t) continue;
        if(b == t) have.insert(a);
        g[a].insert(b);
        gr[b].insert(a);
    }
    for (int i = 0; i < n; ++i)
            if (!used[i])
                dfs1 (i);
    used.assign (n+2, false);
    for (int i = 0; i < n; ++i) {
            int v = order[n-1-i];
            if (!used[v]) {
                dfs2 (v);
                for (auto cur : component[id]) scc[cur] = id;
                id++;
              }
        }
    for (int i = 0; i < id ; i++)
        for (auto node : component[i])
            for (auto child : gr[node])
                if (scc[node] != scc[child])
                    adj[scc[child]].insert(scc[node]);
    set<int> st;
    for(auto child : gr[t]){
        if( solve (scc[child]) == 1){
            int id = scc[child];
            int mn = -1;
            bool cond = true;
            for(auto x : component[id]){
                if(have.count(x) && mn == -1)
                    mn = x;
                else {
                    if(have.count(x)) cond = false;
                }
            }
            if(cond)
            st.insert(mn);
        } 
    }
    cout << sz(st) << endl;
    for(auto cur : st) cout << cur << endl;
 }

