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
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {-1,0,1,1,-1,1,0,-1};
int a[MAXN][MAXN];
int n,m;
bool valid(int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int ans[MAXN][MAXN];
pair<int,int> dp[MAXN][MAXN];
int vis[MAXN][MAXN];
pair<int,int> dfs(int x, int y){
    if(vis[x][y]) return dp[x][y];
    vis[x][y] = true;
    int mini = a[x][y];
    int mx = x;
    int my = y;
    for(int k = 0;k < 8; k++){
        int xx = dx[k] + x;
        int yy = dy[k] + y;
        if(valid(xx,yy) && a[xx][yy] < mini){
            mini = a[xx][yy];
            mx = xx;
            my = yy;
        }
    }
    if(mx == x && my  == y) return dp[x][y] = {x,y};
    return dp[x][y] = dfs(mx,my);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            auto cur = dfs(i,j);
            ans[cur.first][cur.second]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}