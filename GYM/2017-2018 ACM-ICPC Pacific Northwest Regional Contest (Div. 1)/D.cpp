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
vector<pair<int,int>> g[MAXN];
int bad[MAXN],in[MAXN];
set<pair<int,int>> vis;
void go(int node, int par){
    bad[node] = 1;
    in[node]++;
    if(in[node] > 3) return;
    for(auto cur : g[node]){
        int child = cur.first;
        if(child == par) continue;
        go(child, node);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v,c);
        g[v].emplace_back(u,c);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        map<int,int> cnt;
        for(auto cur : g[i]){
            int child = cur.first;
            int col = cur.second;
            cnt[col]++;
        }
        for(auto cur : g[i]){
            int child = cur.first;
            int col = cur.second;
            if(cnt[col] >= 2) go(child,i);
        }

    }
     for(int i = 1; i <= n; i++){
        if(!bad[i]) cnt++;
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++){
        if(!bad[i]) cout << i << endl;
    }
}