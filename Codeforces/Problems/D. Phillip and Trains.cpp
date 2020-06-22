#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[5][1000];
bool valid (int i , int j){
    if (i < 0 or i >= 3) return false;
    if (j>=n) return true;
    return a[i][j]=='.';
}
int main (){
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        int vis[4][n];
        int x,y;
        memset(vis,0,sizeof vis);
        for (int i = 0; i < 3;i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
                vis[i][j] = 0;
                if (a[i][j] == 's')  y=i,x=j;
            }
        }
        bool cond = false;
        queue<pair<int,int>>q;
        q.push({y,x});
        while (!q.empty()){
            int i =q.front().first;
            int j =q.front().second;
            q.pop();
            if (j >= n){
                 cond = true;
                 break;
            }

            if (i < 0 or  i >=3) continue;
            if (vis[i][j] or (a[i][j] != '.' && a[i][j] !='s')) continue;
            if (!valid(i,j+1)) continue;
            vis[i][j] = true;
            a[i][j] = 's';
            if (valid(i+1,j+1))
                q.push({i+1,j+3});
            if (valid(i,j+1) )
                q.push({i,j+3});
            if (valid(i-1,j+1))
                q.push({i-1,j+3});
        }
        if (cond) cout << "YES\n";
        else cout << "NO\n";
    }
}
