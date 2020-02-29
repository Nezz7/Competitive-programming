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
LL sz[MAXN];
LL const mod = 1e9 + 7;
LL leaf;
vector<vector<int>> g;
int n, l ;
void dfs (int node){
    if (sz[node] != 0) return;
    if (node > l) sz[node] = 1,leaf++;
    for (auto child : g[node]){
        dfs(child);
        sz[node] += sz[child];
        sz[node] %= mod;
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> l;
    g.resize(n+1);
    for (int i = 1; i <= l; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k ;j++){
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    dfs(1);
    cout << sz[1] << " " << leaf << endl;
}