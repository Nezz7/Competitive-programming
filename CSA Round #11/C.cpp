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
 int p[MAXN],sz[MAXN];
 int find_set (int x){
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
 }
 bool union_set (int u, int v){
    u = find_set(u);
    v = find_set(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u,v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> edges;
    vector<pair<pair<int,int>,pair<int,int>>> out;
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        if (!union_set(u,v)){
            edges.emplace_back(u,v);
        }
    }
    int j = edges.size();
    j --;
    for (int i = 2; i <= n; i++){
        if (find_set(i) != find_set(1)){
            if (j == -1){
                cout << -1;
                return 0;
            }
            out.push_back({edges[j],{i,1}});
            union_set(1,i);
            j--;
        }
    }
    cout << out.size() << endl;
    for (auto cur : out){
        cout << cur.f.f << " " << cur.f.s << " " << cur.s.f << " " << cur.s.s << endl;
    }
 }
