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
vector<int> adj[MAXN];
int a[MAXN];
int ans = 0;
void dfs(int node, int dep){
    ans = max(ans, dep);
    for(auto child : adj[node]){
        dfs(child, dep + 1);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        queue<int> p;
        p.push(1);
        int last = -1;
        for(int i = 1; i < n; i++){
            if(last > a[i]){
                p.pop();
            }
            adj[p.front()].push_back(a[i]);
            p.push(a[i]);
            last = a[i];
        }
        dfs(1,0);
        cout << ans << endl;
        for(int i = 0; i <= n; i++) adj[i].clear();
    }
}