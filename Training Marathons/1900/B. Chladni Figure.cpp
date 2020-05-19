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
vector<vector<int>> g;
map<vector<int>,int> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i  = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u] . pb( (u - v + n) % n);
        g[v] . pb( (v - u + n) % n);
    }
    for(int i = 1; i <= n; i++){
        sort(all(g[i]));
        mp[g[i]] ++;
    }
    int g = 0;
    for(auto cur : mp){
        g = __gcd(cur.second,g);
    }
    if(g == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}