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
LL sumX[MAXN], sumY[MAXN], x[MAXN], y[MAXN];
LL ans[MAXN];
vector<int> g[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<LL,int>> arr;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        arr.emplace_back(x[i] - y[i], i);
    }
    sort(all(arr)); 
    for(int i = 0; i < n; i++){
        sumX[i + 1] = x[arr[i].second] + sumX[i];
    }

    for(int i = n - 1; i >= 0; i--){
        sumY[i] = y[arr[i].second] + sumY[i + 1];
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 0; i < n; i++){
        int idx = arr[i].second;
        ans[idx] = sumX[i] + i * y[idx] + sumY[i + 1] + (n - i - 1) * x[idx];
        for(auto cur : g[idx]){
            LL a = x[cur] + y[idx];
            LL b = x[idx] + y[cur];
            ans[idx] -= min(a,b);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}