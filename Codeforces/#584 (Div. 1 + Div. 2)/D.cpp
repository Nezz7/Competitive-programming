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
int a[MAXN],b[MAXN],good[MAXN],favor[MAXN];
int vis[MAXN];
vector<vector<int>> g;
void go(int i);
void eat(int i){
    int u = a[i];
    int v = b[i];
    if(!favor[u]){
        good[i] = 1;
        favor[u] = 1;
    }
    if(!favor[v]){
        good[i] = 1;
        favor[v] = 1;
    }
    go(u);
    go(v);
}
void go(int i){
    if(vis[i]) return;
    vis[i] = 1;
    for(auto child : g[i]){
        if(!good[child])
            eat(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n >> k;
    g.resize(n + 1);
    for(int i = 0; i < k; i++){
        cin >> a[i] >> b[i];
        g[a[i]].pb(i);
        g[b[i]].pb(i);
    }
    for(int i = 1; i <= n; i++){
        go(i);
    }
    int ans = 0;
    for(int i = 0; i < k; i++) ans += (good[i] == 0);
    cout << ans << endl;
}