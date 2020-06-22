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
 int const MAXN = 500 + 9;
 int vis[MAXN][MAXN];
 char a[MAXN][MAXN];
 int dx [] = {0,0,1,-1};
 int dy [] = {1,-1,0,0};
 int n, m;
 vector<pair<char,pair<int,int>>> out;
 bool valid (int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
 }
 void DFS (int i, int j){
    vis[i][j] = 1;
    a[i][j] = 'B';
    out.push_back ({'B',{i,j}});
    for (int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid (x,y) && !vis[x][y] && a[x][y] != '#') DFS(x,y);
    }
    for (int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid (x,y) && a[x][y] == 'B'){
            a[i][j] = 'R';
            out.push_back ({'D',{i,j}});
            out.push_back ({'R',{i,j}});
            break;
        }
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && a[i][j] != '#') DFS(i,j);
    }
    cout << sz(out) << endl;
    for (auto cur : out){
        cout << cur.first << " " << cur .second . first + 1  << " " << cur. second . second + 1 << endl;
    }
 }
