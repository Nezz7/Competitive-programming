#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int vis[30][30][2000];
string a[30];

bool valid (int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int main(){
    while (cin >> m >> n && n && m){
        int d = 0;
        int mask = 0;
        map<pair<int,int>,int> mp;
        int x,y;
        memset(vis,0,sizeof vis);
        for (int i = 0; i < n; i++){
                cin >> a[i];
            for (int j = 0; j < m; j ++){
                if (a[i][j] == 'o'){
                     x = i;
                     y = j;
                }
                if (a[i][j] == '*'){
                     mask |= (1 << d);
                     mp[{i,j}]= ++d;
                }
            }
        }
            queue <pair<pair<int,int>,int>> q;
            q.push({{x,y},mask});
            int ans = -1;
            while (!q.empty()){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int cmask = q.front().second;
                q.pop();
                if (cmask == 0){
                    ans = vis[x][y][cmask];
                    break;
                }
                for (int k = 0; k < 4; k++){
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    int mask = cmask;
                    if (valid (xx,yy) && a[xx][yy]!='x'){
                        if (mp[{xx,yy}]){
                            int d = mp[{xx,yy}];
                            mask = cmask & (~(1 << (d-1)));
                        }
                        if (vis[xx][yy][mask]) continue;
                        vis[xx][yy][mask] = 1 + vis[x][y][cmask];
                        q.push({{xx,yy},mask});
                    }
                }
            }
            cout << ans << "\n";
        }

}
