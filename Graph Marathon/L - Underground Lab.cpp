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
 vector<vector<int>> g;
 int vis[MAXN];
 vector<int> tour;
 void DFS (int u){
    vis [u] = true;
    tour.push_back(u);
     for (auto v : g[u]){
            if (!vis[v]){
                 DFS (v);
                 tour.push_back(u);
            }
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    g.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1);
    int sz = (2 * n + k - 1)/k;
    int j = 0;
    int p = tour.size();
    for (int i = 0; i  < k ; i++){
        if (p == j){
            cout << "1 1" << endl;
            continue;
        }
        int l;
        if (p - j >= sz){
            cout << sz << " ";
            l = sz;
        }else {
            cout << p - j << " ";
            l = p - j;
        }
        for (int t = 0;t < l; t++) cout << tour[j+t]<<" ";
        cout << endl;
        j += l;
    }
 }
