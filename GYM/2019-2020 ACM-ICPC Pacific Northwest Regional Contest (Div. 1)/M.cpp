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
int const MAXN = 1e3 + 9;
int n, m;
char a[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[] = {0,0,-1,1,1,-1,-1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
bool valid (int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs (int x, int y){
    if (a[x][y] != '.') return;
    vis[x][y] = 1;
    for (int k = 0; k < 8; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (!valid(xx,yy) or vis[xx][yy] or a[xx][yy] != '.') continue;
        if ((k == 6) && valid (x-1,y) && valid(x,y+1) &&  (a[x-1][y] != '/'  or a[x][y+1] != '/')) continue;
        if ((k == 7) && valid (x,y-1) && valid(x+1,y) &&  (a[x][y-1] != '/'  or a[x+1][y] != '/')) continue;
        if ((k == 4) && valid (x+1,y) && valid(x,y+1) &&  (a[x+1][y] != '\\'  or a[x][y+1] != '\\')) continue;
        if ((k == 5) && valid (x,y-1) && valid(x-1,y) &&  (a[x-1][y] != '\\'  or a[x][y-1] != '\\')) continue;
        dfs(xx,yy);
    }
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m ;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < m-1; j++){
            if (a[i][j] == '/' && a[i][j+1] == '\\' && a[i+1][j] == '\\' && a[i+1][j+1] == '/') ans++;
        }
    for (int i = 0; i < n; i++) dfs(i,0),dfs(i,m-1);
    for (int i = 0; i < m; i++) dfs(0,i),dfs(n-1,i);
    
   
   for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j] && a[i][j] == '.') ans++,dfs(i,j);
          
      
    cout << ans << endl;

}