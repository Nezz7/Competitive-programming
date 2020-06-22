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
int const MAXN = 1040;
int n;
char a[MAXN][MAXN];
int x[MAXN][MAXN], y[MAXN][MAXN];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string mv ="LRUD";
string nv ="RLDU";
bool valid (int i, int j){
    return i > 0 && i <= n && j > 0 && j <= n;
}
void dfs(int i, int j){
    if (x[i][j] == i  && y[i][j] == j) a[i][j] = 'X';
    if (x[i][j] == -1){
        for (int k = 0; k < 4; k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if (valid(xx,yy) && x[xx][yy] == x[i][j] && y[xx][yy] == y[i][j]){
                a[i][j] = nv[k]; 
            }
        }
    }
    for (int k = 0; k < 4; k++){
        int xx = i + dx[k];
        int yy = j + dy[k];
        if (valid(xx,yy) && !a[xx][yy] && x[xx][yy] == x[i][j] && y[xx][yy] == y[i][j]){
            a[xx][yy] = mv[k]; 
            dfs(xx,yy);
      }
    }
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    memset(a,0,sizeof a);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cin >> x[i][j] >> y[i][j];

    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (x[i][j] == i  && y[i][j] == j) dfs(i,j);
            if (x[i][j] == -1 && !a[i][j]){
                dfs(i,j);
            }
        }
    }
    bool cond = true;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
                if(!a[i][j]) cond = false;
        }
    }
    if (!cond){
        cout << "INVALID" << endl;
        return 0;
    }
    cout << "VALID" << endl;
    cerr << n;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}