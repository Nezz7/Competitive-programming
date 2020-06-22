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
vector<vector<int>>g;
vector<pair<int,int> > ed;
bool is_leaf (int x){
    return g[x].size() == 1;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for (int i = 0; i < n - 1; i++){
        int u,v;
        cin >> u >> v;
        ed.emplace_back(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int l = 0;
    for (int i = 1; i <= n; i++){
        l += is_leaf(i);
    }
    int cur = 0;
    for(auto x : ed){
        int u = x.f;
        int v = x.s;
        if (is_leaf(u) or is_leaf(v)){
            cout << cur  << endl;
            cur++;
        }else {
            cout << l << endl;
            l++;
        }
    }
}