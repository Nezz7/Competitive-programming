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
int const MAXN = 1000 + 9;
char a[MAXN][MAXN];
set<int> col,row;
int dx [] = {1,-1,0,0};
int dy [] = {0,0,1,-1};
int vis[MAXN][MAXN];
int n, m;
bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(int x, int y){
    if(a[x][y] == '.') return;
    vis[x][y] = true;
    for(int k = 0; k < 4; k++){
        int xx = dx[k] + x;
        int yy = dy[k] + y;
        if(valid(xx,yy) && !vis[xx][yy]) dfs(xx,yy);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    int black = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            black += (a[i][j] == '#');
            if(a[i][j] == '#') row.insert(i),col.insert(j);
        }
    }
    if(!black){
        cout << 0 << endl;
        return 0;
    }
    if((sz(row) == n && sz(col) != m) or (sz(row) != n && sz(col) == m)) {
        cout << -1 << endl;
        return 0;
    }
    bool cond = true;
    for(int i = 0; i < n; i++){
        int cur = 0;
        int s = 0;
        for(int j  = 0; j < m; j++){
            if(a[i][j] == '#' && s){
                if(cur) cond = false;
            }
            if(a[i][j] == '.') cur++;
            if(a[i][j] == '#') s = 1,cur = 0;
        }
    }
    for(int j  = 0; j < m; j++){
        int s = 0;
        int cur = 0;
        for(int i = 0; i < n; i++){
             if(a[i][j] == '#' && s){
                if(cur) cond = false;
            }
            if(a[i][j] == '.') cur++;
            if(a[i][j] == '#') s = 1,cur = 0;
        }
  
    }
    if(!cond){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && a[i][j] == '#') {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
}