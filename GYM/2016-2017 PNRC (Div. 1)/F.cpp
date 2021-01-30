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
int const MAXN = 1000 + 9;
int x[MAXN], y[MAXN];
vector<int> g[3*MAXN], gr[3*MAXN];

void add_edge_h(int i, int j){
    // i or j
    g[2 * i + 1].push_back(2 * j);
    gr[2 * j].push_back(2 * i + 1);
    g[2 * j + 1].push_back(2 * i);
    gr[2 * i].push_back(2 * j + 1);
}
void add_edge_v(int i, int j){
    // !i or !j
    g[2 * i].push_back(2 * j + 1);
    gr[2 * j + 1].push_back(2 * i);
    g[2 * j].push_back(2 * i + 1);
    gr[2 * i + 1].push_back(2 * j);
}
vector<int> order;
bool vis[3*MAXN];
void dfs_order(int node){
    vis[node] = 1;
    for(auto child : g[node]){
        if(!vis[child])
            dfs_order(child);
    }
    order.push_back(node);
}
int id = 0;
int comp[3*MAXN];
void dfs(int node){
    vis[node] = 1;
    comp[node] = id;
    for(auto child : gr[node]){
        if(!vis[child])
            dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, r, m;
    cin >> n >> r >> m;
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
                if(x[i] == x[j]){
                    int d = abs(y[i] - y[j]) - 1;
                    if(d < 2 * r){
                        add_edge_v(i, j);
                    }
                }
                if(y[i] == y[j]){
                     int d = abs(x[i] - x[j]) - 1;
                    if(d < 2 * r){
                        add_edge_h(i, j);
                    }
                }
        }
    }
    for(int i = 0; i < 2 * m; i++){
        if(!vis[i])
            dfs_order(i);
    }
    memset(vis,false, sizeof(vis));
    reverse(all(order));
    for(auto v : order){
        if(!vis[v]){
            id++;
            dfs(v);
        }
    }
    for(int i = 0; i < m; i++){
        if(comp[2 * i] == comp[2*i + 1]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}