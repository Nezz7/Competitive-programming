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
int const MAXN = 1e6 + 9;
int a[MAXN],b[MAXN],ans[MAXN];
vector <int> g[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pair<int,int>> order;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        order.emplace_back(a[i],i);
    }
    sort(all(order));
    for(auto cur : order){
        int node = cur.second;
        set<int>  st;
        for(auto child : g[node])
            st.insert(b[child]);
        int mex = 1;
        while(st.count(mex)) mex++;
        if(mex == a[node]){
            b[node] = a[node];
        }else {
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto cur : order)
        cout<< cur.second << ' ';
}