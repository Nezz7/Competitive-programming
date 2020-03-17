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
int n,col[MAXN],sz[MAXN];
vector<vector<int>> g;
vector<vector<int>> st;
set<int> d;
LL ans = 0;
LL get(LL x){
    return x * (x - 1) / 2; 
}
void dfs (int u, int p){
    st[col[u]].push_back(u);
    sz[u] = 1;
    for (auto v : g[u]){
        if (v == p) continue;
        dfs(v,u);
        LL cur = 0;
        while(st[col[u]].back() != u){
            cur += sz[st[col[u]].back()];
            st[col[u]].pop_back();
        }
        ans -= get(sz[v] - cur);
        sz[u] += sz[v];
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int i = 0;
    while (cin >> n){
        i++;
        g.clear();
        g.resize(n+1);
        st.clear();
        st.resize(n+1);
        d.clear();
        for (int i = 1; i <= n; i++){
            cin >> col[i];
            sz[i] = 0;
            d.insert(col[i]);
        }
        for (int i  = 0; i < n - 1; i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans = n * 1LL * (n-1) * 1LL * sz(d)/2;
        dfs(1,1);
        for (int i = 1; i <= n; i++){
            LL cur = n;
            for (auto x : st[i]){
                cur -= sz[x];
            }
            if(cur < n) ans -= get(cur);
        }
        cout << "Case #"<< i <<": "<< ans << endl;
    }
}