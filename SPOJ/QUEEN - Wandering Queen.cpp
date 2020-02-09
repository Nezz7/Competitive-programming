#include <bits/stdc++.h>
using namespace std;
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={0,1,-1,0,1,-1,1,-1};
int n,m;
char a[1500][1500];
int vis[1002][1002];
int done[1002][1002];
bool valid (int x,int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m;
        int x,y;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                    vis[i][j] = 1e9;
                    done [i][j] = 0;
            }
        }
        for (int i  = 0 ; i < n; i++)
            for (int j  = 0 ; j < m; j++){
                cin >> a[i][j];
                if (a[i][j] == 'S'){
                    x = i;
                    y = j;
                }
            }
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y] = 0;
        int ans = 1e9;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (a[x][y] == 'F'){
                ans = min(ans,vis[x][y]);
                break;
            }
            for (int i = 0; i < 8 ;i++){
                for (int j = 1; j < 1001; j++){
                    int xx = x + j * dx[i];
                    int yy = y + j * dy[i];
                    int d = vis[x][y] + 1;
                    if (!valid(xx,yy) or a[xx][yy]== 'X' or (done[xx][yy] & (1 << i))) break;
                        if (!done[xx][yy])
                            q.push({xx,yy});
                        done[xx][yy] |= (1 << (i));
                        vis[xx][yy] = min(d,vis[xx][yy]);

                }
            }
        }
        if (ans != 1e9)
            cout << ans << "\n";
        else cout << -1 << "\n";
    }
}
