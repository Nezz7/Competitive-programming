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
vector<pair<int,int>> edges;
int ans = 0;
int n,m;
int p[7];
void solve(){
    set<pair<int,int>> st;
    for(auto e : edges){
        if(p[e.first] && p[e.second])
            st.insert(minmax(p[e.first],p[e.second]));
    }
    ans = max(ans,sz(st) );
}
void go(int pos){
    if(pos == n){
        solve();
        return;
    }
    for(int i = 0; i <= 6; i++){
        p[pos] = i;
        go(pos + 1);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        edges.push_back(minmax(u,v));
    }
    go(0);
    cout << ans << endl;
}