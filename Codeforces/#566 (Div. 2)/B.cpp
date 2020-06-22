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
int n,m;
char a[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
bool check (int x, int y){
    memset(vis,0,sizeof (vis));
    if(a[x][y] != '*') return false;
    vis[x][y] = 1;
    bool cond = false;
    for(int i = y - 1; i >= 0; i--){
        if(a[x][i] == '*') cond = true,vis[x][i] = 1;
        else break;
    }
    if(!cond) return false;
    cond = false;
    for(int i = y + 1; i < m; i++){
        if(a[x][i] == '*') cond = true,vis[x][i] = 1;
        else break;
    }
    if(!cond) return false;
    cond = false;
    for(int i = x - 1; i >= 0; i--){
        if(a[i][y] == '*') cond = true,vis[i][y]= 1;
        else break;
    }
    if(!cond) return false;
    cond = false;
    for(int i = x + 1; i < n; i++){
        if(a[i][y] == '*') cond = true,vis[i][y] = 1;
        else break;
    }
    if(!cond) return false;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && a[i][j] == '*') return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n -1; i++){
        for (int j = 1; j < m - 1; j++){
            bool cond = true;
            for (int k = 0; k < 5; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                cond &= (a[x][y] == '*');
            }
            if (cond){
                if (check(i,j)) cout << "yes" << endl;
                else cout << "no";
                return 0;
            }
        }
    }
    cout << "no";
}