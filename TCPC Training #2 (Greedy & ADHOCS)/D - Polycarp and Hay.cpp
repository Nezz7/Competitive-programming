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
 int const MAXN = 1005;
 vector<pair<LL,pair<int,int>>> v;
 int dx[] = {0,0,-1,1};
 int dy[] = {1,-1,0,0};
 int vis[MAXN][MAXN], a[MAXN][MAXN];
int sz[MAXN*MAXN], p[MAXN*MAXN];
LL n, m, k, cur_nbr, val;
 bool valid (int x, int y){
    return x >= 0 && y >=0 && x < n && y < m;
 }
 void dfs (int x, int y){
    vis [x][y] = 1;
    cur_nbr--;
    if (cur_nbr == 0) return ;
    for (int k = 0; k < 4; k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (valid(xx,yy) && a[xx][yy]>= val && !vis[xx][yy] && cur_nbr){
               dfs(xx,yy);
            }
    }
 }
int get_id (int x, int y ){
    return x*m + y;
}
void init (){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            p[get_id(i,j)] = get_id(i,j);
            sz[get_id(i,j)] = 1;
        }
}
int find_set (int x){
    if (p[x] == x) return x;
    return p[x] = find_set (p[x]);
}
void union_set (int u, int v){
     u = find_set(u);
     v =  find_set(v);
    if (u != v){
        if (sz[u] < sz[v]) swap(u,v);
        p[v] = u;
        sz[u] += sz[v];
    }
}
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
             cin >> a[i][j];
           v.push_back({a[i][j],{i,j}});
        }
    }
    init();
    sort(rall(v));
    for (int i = 0; i < sz(v); i++){
         val = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        for (int k = 0; k < 4; k++){
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (valid(xx,yy) && a[xx][yy]>= val){
                union_set(get_id(xx,yy),get_id(x,y));
            }
        }
        if (k % val == 0 && sz[find_set(get_id(x,y))] >= k/val){
             cur_nbr = k/val;
             cout << "YES\n";
             dfs(x,y);
             for (int i = 0; i < n; i++){
                for (int j  = 0; j < m; j++){
                    if (vis[i][j]) cout << val << " ";
                    else cout <<  "0 ";
                }
                cout << endl;
             }
             return 0;
        }
    }
    cout << "NO\n";
 }
