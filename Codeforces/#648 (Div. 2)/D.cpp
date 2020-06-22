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
int const MAXN = 55;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int used[MAXN][MAXN];
char a[MAXN][MAXN];
int n, m;
bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}
void dfs(int i, int j){
    used[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(valid(x,y) && a[x][y] != '#' && !used[x][y])
            dfs(x,y);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(used,0,sizeof(used));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        dfs(n - 1, m - 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'B' && used[i][j]){
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(valid(x,y) && a[x][y] == '.') a[x][y] = '#';
                    }
                 }
            }
        }
        memset(used,0,sizeof(used));
        if(a[n - 1][m - 1] != '#')
        dfs(n - 1, m - 1);
        bool cond = true;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'B' && used[i][j]) cond = false;
                if(a[i][j] == 'G' && !used[i][j]) cond = false;
            }
        if(cond) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}