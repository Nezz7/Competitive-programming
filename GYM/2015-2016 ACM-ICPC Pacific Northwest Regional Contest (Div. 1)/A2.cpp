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
int const MAXN = 500 + 9;
LL p[MAXN], d[MAXN][MAXN], dist[MAXN][MAXN];
vector < pair < int, pair<int, int> > > a;
int n, m;
int solve(int pos, vector < pair <int, int> > planes){
    if (pos >= m) return 0;
    bool find = false;
    int before = a[pos].first;
    int u = a[pos].second.first;
    int v = a[pos].second.second;
    int ret = 1e9;
    for(int i = 0; i < sz(planes); i++){
        if(planes[i].second == u){
            if(planes[i].first + p[u] <= before){
                int f = planes[i].first;
                int s = planes[i].second;
                planes[i].first = before + d[u][v];
                planes[i].second = v;
                ret = min(solve(pos + 1, planes), ret);
                planes[i] = {f,s};
                return ret;
            }
        }else 
        if(planes[i].first + p[planes[i].second] + dist[planes[i].second][u] + p[u] <= before){
            int f = planes[i].first;
            int s = planes[i].second;
            planes[i].first = before + d[u][v];
            planes[i].second = v;
            ret = min(solve(pos + 1, planes), ret);
            planes[i] = {f,s};
        }
    }
    if(ret == 1e9){
        planes.emplace_back(before + d[u][v], v);
        ret = min(1 + solve(pos + 1, planes), ret);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> d[i][j], dist[i][j] = d[i][j];
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + p[k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        int s, f, t;
        cin >> s >> f >> t;
        s--;
        f--;
        a.push_back({t, {s, f}});
    }
    sort(all(a));
    vector< pair<int,int> > planes;
    cout << solve(0, planes);
}