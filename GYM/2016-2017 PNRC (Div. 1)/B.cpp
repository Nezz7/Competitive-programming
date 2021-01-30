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
int const MAXN = 100 + 9;
int n, m, sx, sy, ex, ey;
char a[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
string path;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
string dir = "DULR";
bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < n &&  y < m && a[x][y] != '#';
}
 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'R'){
                sx = i, sy = j;
            }
            if(a[i][j] == 'E'){
                ex = i, ey = j;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < MAXN; k++)
                dp[i][j][k] = 1e9;
        }
    }
    cin >> path;
    deque<pair<pair<int,int>,int>> dq;
    dq.push_back({{sx,sy},0});
    dp[sx][sy][0] = 0;
    while(!dq.empty()){
        int i = dq.front().first.first;
        int j = dq.front().first.second;
        int k = dq.front().second;
        dq.pop_front();
        if(i == ex && j == ey){
            cout << dp[i][j][k];
            return 0;
        }
        if(k >= path.size()){
            for(int kk = 0; kk < 4; kk++){
                int x = i + dx[kk];
                int y = j + dy[kk];
                if(valid(x,y) && dp[x][y][k] > dp[i][j][k] + 1){
                    dp[x][y][k] = dp[i][j][k] + 1;
                    dq.push_back({{x,y},k});
                }
            }
            continue;
        }
        for(int kk = 0; kk < 4; kk++){
            int x = i + dx[kk];
            int y = j + dy[kk];
            if(path[k] == dir[kk]){
                if(!valid(x,y)) {
                    if(dp[i][j][k + 1] > dp[i][j][k]){
                        dp[i][j][k + 1] = dp[i][j][k];
                        dq.push_front({{i,j},k+1});
                    }
                }else {
                    if(dp[x][y][k + 1] > dp[i][j][k]){
                        dp[x][y][k + 1] = dp[i][j][k];
                        dq.push_front({{x,y},k+1});
                    }
                }
            }
              if(valid(x,y)) {
                   if(dp[x][y][k] > dp[i][j][k] + 1){
                          dp[x][y][k] = dp[i][j][k] + 1;
                          dq.push_back({{x,y},k});
                      }
              }
        }
      	if(dp[i][j][k + 1] > dp[i][j][k] + 1){
            dp[i][j][k + 1] = dp[i][j][k] + 1;
            dq.push_back({{i,j},k + 1});
        }
              
    }
 
}
 