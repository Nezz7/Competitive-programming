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
 int const MOD = 1e9 + 7;
 int vis[MAXN];
 LL sz ;
 vector<vector<int>> adj;
 LL mul (LL a, LL b){
    return (a * b) % MOD;
 }
 bool cond;
 bool loop;
 void DFS (int node,int p){
    vis[node] = true;
    sz++;
    for (auto child : adj[node]){
        if (child == node){
            loop = true;
        }
        if(!vis [child]){
            DFS(child,node);
        }else if (child != p){
            cond = true;
        }
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    adj.resize(2 * n + 2);
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LL ans = 1;
    for (int i = 1; i <= 2 * n ;i++){
        if (!vis[i]){
            sz = 0;
            cond = false;
            loop = false;
            DFS(i,i);
            if (cond) sz = 2;
            if (loop) sz = 1;
            ans = mul(ans,sz);
        }
    }
    cout << ans;
 }
