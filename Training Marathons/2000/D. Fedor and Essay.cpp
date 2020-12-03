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
map<string,int> id;
int len[MAXN], r[MAXN], scc[MAXN];
vector<int> g[MAXN], gr[MAXN], adj[MAXN];
vector<bool> used;
vector<int> order;
int p = 0;
void dfs1 (int v) {
        used[v] = true;
        for (auto u : g[v])
            if (!used[u])
                dfs1 (u);
        order.push_back (v);
 }
void dfs2 (int v, int& scc_r, int& scc_l) {
        used[v] = true;
        if(r[v] < scc_r){
            scc_r = r[v];
            scc_l = len[v];
        }else if(r[v] == scc_r) 
            scc_l = min(scc_l, len[v]); 
        scc[v] = p;
        for (auto u : gr[v])
            if (!used[u]){
                dfs2 (u, scc_r, scc_l);
            }
}
pair<int,int> dp[MAXN];
int vis[MAXN];
pair<int,int> solve(int node){
    if(vis[node]) return dp[node];
    vis[node] = 1;
    dp[node] = {r[node], len[node]};
    for(auto child : adj[node]){
        dp[node] = min(dp[node], solve(child));
    }
    return dp[node];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int m;
    cin >> m;
    vector<int> words;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int cnt = 0;
        for(auto& c : s){
            c = tolower(c);
            cnt += c == 'r';
        }
        if(id.count(s) == 0){
            len[p] = s.size();
            r[p] = cnt;
            id[s] = p++;
        }
        words.push_back(id[s]);
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        int cntA = 0, cntB = 0;
        for(auto& c : a){
            c = tolower(c);
            cntA += c == 'r';
        }
        if(id.count(a) == 0){
            len[p] = a.size();
            r[p] = cntA;
            id[a] = p++;
        }
        for(auto& c : b){
            c = tolower(c);
            cntB += c == 'r';
        }
        if(id.count(b) == 0){
            len[p] = b.size();
            r[p] = cntB;
            id[b] = p++;
        }
        g[id[a]].push_back(id[b]);
        gr[id[b]].push_back(id[a]);
    }
    int sz_node = p;
    used.assign (sz_node + 2,false);

    for (int i = 0; i < sz_node; ++i)
            if (!used[i])
                dfs1 (i);
    used.assign (sz_node + 2,false);
    for (int i = 0; i < sz_node; ++i) {
        int v = order[sz_node - 1 - i];
        if (!used[v]) {
            int scc_r = 1e9, scc_l = 1e9;
            dfs2 (v, scc_r, scc_l);
            len[p] = scc_l;
            r[p] = scc_r; 
            p++;
        }
    }
    for(int u = 0; u < sz_node; u++){
        for(auto v : g[u]){
            if(scc[u] != scc[v]){
                adj[scc[u]].push_back(scc[v]);
            }
        }
    }
    LL ans_r = 0, ans_l = 0;
    for(auto x : words){
        auto ret = solve(scc[x]);
        ans_r += ret.first;
        ans_l += ret.second;
    }
    cout << ans_r << " "<< ans_l << endl;

}