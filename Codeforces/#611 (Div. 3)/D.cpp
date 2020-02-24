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
int a[MAXN];
map<int,int> dist;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    queue<int> q;
    vector<int> v;
    for (int i = 0; i < n; i++){ 
        cin >> a[i];
        dist[a[i]] = 0;
        q.push(a[i]);
    }
    LL  ans  = 0;
    while (!q.empty()){
        int u = q.front ();
        q.pop();
        if (dist[u] != 0){
            ans += dist[u];
            v.pb(u);
            if (sz(v) == m) break;
        }
        if (dist.count(u + 1) == 0){
            dist[u + 1] = 1 + dist[u];
            q.push(u + 1);
        }
        if (dist.count(u - 1) == 0){
            dist[u - 1] = 1 + dist[u];
            q.push(u - 1);
        }

    }
    cout << ans << endl;
    for (auto cur : v) cout << cur << " ";
}