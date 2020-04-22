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
int const MAXN2 = 2e6 + 9;
vector<pair<int,int>> val[MAXN2];
int n,m;
int pref[3][MAXN][MAXN];
char g[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {1,-1,0,1,-1,0,1,-1};
bool valid(int x, int y){
    return x >= 1 && x <= n &&  y >= 1 && y <= m;
}
int sz;
int count_white(int x1, int y1 , int x2, int y2){
    if (!valid(x1,y1) or !valid(x2,y2)) return 1e9;
    return pref[0][x2][y2] - pref[0][x1 - 1][y2] - pref[0][x2][y1 - 1] + pref[0][x1 - 1][y1 - 1];
}
int count_black(int x1, int y1 , int x2, int y2){
    if (!valid(x1,y1) or !valid(x2,y2)) return 1e9;
    return pref[1][x2][y2] - pref[1][x1 - 1][y2] - pref[1][x2][y1 - 1] + pref[1][x1 - 1][y1 - 1];
}
bool border (int i, int j, int x, int y){
    if (!valid(i,j)) return false;
    int l = 2*x+y;
    int d = 3*x + 2*y;
    if (count_black(i, j, i, j+ l+ 1)) return false;
    if (count_black(i, j, i + d , j) ) return false;
    if (count_black(i, j + l +1, i + d ,j + l+1 ) ) return false;
    if (count_black(i + d +1, j, i + d , j + l +1)) return false;
    return true; ;
}
bool isA(int i, int j, int x, int y){
    if (!valid(i,j) or !border(i,j,x,y)) return false;
    int ret = count_black(i + x + 1, j + x + 1,i + x  + y, j + x  + y);
        ret += count_black(i + 2 * x + y+ 1, j + x + 1,i + 2*x  + 2*y + x, j + x  + y );
    return ret == 0;
}
bool isB(int i, int j, int x, int y){
    if (!valid(i,j) or !border(i,j,x,y)) return false;
    int ret = count_black(i + x + 1, j + x + 1,i + x  + y, j + x  + y);
        ret += count_black(i + 2 * x + y+ 1, j + x + 1,i + 2*x  + 2*y, j + x  + y);
    return ret == 0;
}
bool isC(int i, int j, int x, int y){
    if (!valid(i,j) or !border(i,j,x,y)) return false;
    int ret = count_black(i + x + 1, j + x + 1,i + 2*x  + 2*y, j + 2*x  + y);
    return ret == 0;
}
int get_szA(int x, int y){
    LL l = 2*x+y;
    LL ret = x * l + 4 * x * y + x * l + 2*x*x;
    if (ret > MAXN2) return 0;
    return ret;
}
int get_szB(int x, int y){
    LL l = 2*x+y;
    LL ret = 3*x * l + 4 * x * y ;
    if (ret > MAXN2) return 0;
    return ret;
}
int get_szC(int x, int y){
    LL l = 2*x+y;
    LL ret = 2*x * l + x * ( 2*y+x) ;
    if (ret > MAXN2) return 0;
    return ret;
}
int mni = 1e9;
int mnj = 1e9;
void dfs(int i, int j){
    mni = min(i,mni);
    mnj = min(j,mnj);
    sz++;
    vis[i][j] = 1;
    for(int k = 0; k < 8; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(!vis[x][y] && g[x][y] == '#') dfs(x,y);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (g[i][j] == '#'){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (valid(x,y)) cnt+= (g[x][y] == '.');
                }
                if(cnt == 8) g[i][j] = '.';
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref[0][i][j] = pref[0][i-1][j] + pref[0][i][j-1] - pref[0][i-1][j-1] + (g[i][j] == '.');
            pref[1][i][j] = pref[1][i-1][j] + pref[1][i][j-1] - pref[1][i-1][j-1] + (g[i][j] == '#');
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j] && g[i][j] == '#'){
                mni = 1e9;
                mnj = 1e9;
                sz = 0;
                dfs(i,j);
                if(valid(mni-1,mnj-1)){
                    val[sz].emplace_back(mni-1,mnj-1);
                }
            }
        }
    }
    int ansA = 0, ansB = 0, ansC = 0;
    for(int x = 1; x <= 1000; x++)
        for(int y = 1; y <= 1000; y++){
                int sz = get_szA(x,y);
                for(auto cur : val[sz]){
                    ansA += isA(cur.first,cur.second,x,y);
                }
                 sz = get_szB(x,y);
                for(auto cur : val[sz]){
                    ansB += isB(cur.first,cur.second,x,y);
                }
                 sz = get_szC(x,y);
                for(auto cur : val[sz]){
                    ansC += isC(cur.first,cur.second,x,y);
                }
        }
    cout << ansA << ' ' << ansB << ' ' << ansC <<endl;
}