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
int const MAXN = 30 + 9;
int n, m;
char a[MAXN][MAXN];
int vis[MAXN][MAXN];
bool valid(int x, int y){
    return x >= 0 && x < n && y < m && y >= 0;
}
bool cond = true;
void down(int i, int j){
    vis[i][j] = 1;
    a[i][j] = 'R';
    if(valid(i + 1, j) && !vis[i + 1][j]){
        if(a[i + 1][j] == 'B') cond = false;
        else down(i + 1, j);
    }
    if(valid(i, j + 1) && !vis[i][j + 1]){
        if(a[i][j + 1] == 'B') cond = false;
        else down(i, j + 1);
    }
}
void up(int i, int j){
    vis[i][j] = 1;
    a[i][j] = 'B';
    if(valid(i - 1, j) && !vis[i - 1][j]){
        if(a[i - 1][j] == 'R') cond = false;
        else up(i - 1, j);
    }
    if(valid(i, j - 1) && !vis[i][j - 1]){
        if(a[i][j - 1] == 'R') cond = false;
        else up(i, j - 1);
    }
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
            if(a[i][j] == 'B') up(i,j);
            if(a[i][j] == 'R') down(i,j);
            if(a[i][j] != '.') vis[i][j] = 1;
        }
    }
    if(!cond) cout << 0 << endl;
    else {
        LL ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    LL cnt = 1;
                    for(int k = i; k < n; k++){
                        if(vis[k][j]) break;
                        vis[k][j] = 1;
                        cnt++;
                    }
                    ans *= cnt;
                }
            }
        }
        cout << ans << endl;
    }
}