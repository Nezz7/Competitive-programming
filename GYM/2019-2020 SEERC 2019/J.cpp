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
vector<LL> g[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    for(int i = 0; i < m; i++){
        int u, v , w;
        cin >> u >> v >> w;
        g[u].push_back(w);
        g[v].push_back(w);
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        sort(all(g[i]));
        for(int j = 1; j < sz(g[i]); j+=2){
            ans += g[i][j];
        }
    }
    cout << ans << endl;
}