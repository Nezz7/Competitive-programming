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
int const MAXN = 5000 + 9;
int col[MAXN], ans[MAXN], dp[MAXN][MAXN];
vector<vector<int>> g;
int a[4], cnt, n, m;
vector<int> comp[5001][2];
void check(int s){
    vector<int> nodes;
    queue<int> q;
    q.push(s);
    col[s] = 1;
    while(!q.empty()){
        int u = q.front();
        nodes.pb(u);
        q.pop();
        for(auto child : g[u]){
            if(col[child] == -1){
                col[child] = 1 - col[u];
                q.push(child);
            }else {
                if(col[child] == col[u]){
                    cout << "NO";
                    exit(0);
                }
            }
        }
    }
    for(auto x : nodes){
        comp[cnt][col[x]].pb(x);
    }

}
int solve(int idx, int sum){
    if(idx == cnt) return sum == 0;
    int & ret = dp[idx][sum];
    if(~ ret) return ret;
    ret = 0;
    if(sz(comp[idx][0]) <= sum){
        ret = solve(idx + 1, sum - sz(comp[idx][0]));
    }
     if(sz(comp[idx][1]) <= sum){
        ret |= solve(idx + 1, sum - sz(comp[idx][1]));
    }
    return ret;
}
void print(int idx, int sum){
    if(idx == cnt) return;
    if(sz(comp[idx][0]) <= sum && solve(idx + 1, sum - sz(comp[idx][0]))){
        for(auto x : comp[idx][0]){
            ans[x] = 2;
        }
         for(auto x : comp[idx][1]){
            if(a[1]){
                a[1]--;
                ans[x] = 1;
            }else ans[x] = 3;
        }
        print(idx + 1, sum - sz(comp[idx][0]));
        return ;
    }
    for(auto x : comp[idx][1]){
        ans[x] = 2;
    }
        for(auto x : comp[idx][0]){
        if(a[1]){
            a[1]--;
            ans[x] = 1;
        }else ans[x] = 3;
    }
    print(idx + 1, sum - sz(comp[idx][1]));
    
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp, -1, sizeof (dp));
    cin >> n >> m;
    g.resize(n + 1);
    cin >> a[1] >> a[2] >> a[3];
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(col,-1,sizeof(col));
    for(int i = 1; i <= n; i++){
        if(col[i] == -1) check(i),cnt++;
    }
    if(!solve(0,a[2])){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    print(0,a[2]);
    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }
}