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
int a[MAXN],c[MAXN],b[MAXN];
set<pair<int,int>> st;
vector<vector<int>> adj;
int sz = 0;
void get(int i){
    int idx = sz(adj) - 1;
    while(sz(adj[idx]) < c[i] && a[i]){
        a[i]--;
        adj[idx].pb(i);
        if(a[i] == 0) {
            st.erase({c[i],i});
        }
    }
    auto it = st.upper_bound({sz(adj[idx]) + 1,0});
    if (it == st.end()) return;
    get(it->second);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b[i] = x;
        a[x]++;
    }
    for(int i = 1; i <= k; i++) cin >> c[i];
    for(int i = 0; i < n; i++){
        st.insert({c[b[i]],b[i]});
    }
    for(int i = k; i >= 1; i--){
        while(a[i]){
            adj.emplace_back();
            get(i);
        }
    }
    cout << sz(adj) << endl;
    for(auto cur : adj){
        cout << sz(cur) << " ";
        for(auto x : cur) cout << x << ' ';
        cout << endl;
    }
}