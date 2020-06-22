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
 vector<int> v;
 int p[MAXN],vis[MAXN];
 void DFS (int node){
    vis[node] = 1;
    v.push_back(node);
    if (vis[p[node]] == 0) DFS(p[node]);
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a[n+1];
        for (int i  = 1; i <= n; i++) cin >> p[i],a[i] = 0,vis[i] = 0;
        for (int i  = 1; i <= n; i++){
             if (a[i] == 0){
                 v.clear();
                 DFS(i);
                 for (auto cur : v) a[cur] = sz(v);
             }
        }
        for (int i  = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
 }
