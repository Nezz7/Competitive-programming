#include <bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string a[200];
int vis[200][200][20];
string door = "BYRG";
string key = "byrg";
struct node {
    int x,y;
    bool b[4];
};
void init (node &x,int i, int j){
     x.x = i;
     x.y = j;
     for (int i = 0; i <4; i++){
        x.b[i] = false;
     }
}
void init (node &x,int i, int j, int mask){
     x.x = i;
     x.y = j;
     for (int i = 0; i < 4; i++){
        x.b[i] =(mask & (1 << i));
     }
}
int get_mask (bool b[]){
    int ret = 0;
    for (int i = 0; i < 4;i++){
        if (b[i]) ret |= (1<<i);
    }
    return ret;
}
int n,m;
bool valid(int x,int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main (){

    while (cin >> n >> m, n && m ){
        memset(vis,0,sizeof vis);
        vector<pair<int,int>> exit;
        queue<node> q;
        for (int i = 0; i < n ; i++){
            cin >> a[i];
            for (int j = 0; j < m; j++){
                if (a[i][j] == '*'){
                   node x;
                   init(x,i,j);
                   q.push(x);
                }
                if (a[i][j] == 'X') exit.emplace_back(i,j);
            }
        }
        int ans = 0;
        while (!q.empty()){
            node cur = q.front();
            q.pop();
            int x = cur.x;
            int y = cur.y;
            bool b[4];
            for (int i = 0; i < 4; i++){
                b[i] = cur.b[i];
            }
            int cmask = get_mask(b);
              if (a[x][y] == 'X'){
                    ans = vis[x][y][cmask];
                    break;
            }
            for (int k = 0; k < 4 ;k++){
                int xx = x + dx[k];
                int yy = y + dy[k];
                bool cond = true;
                int mask = cmask;
                if (valid (xx,yy) && a[xx][yy] !='#'){
                    for (int i = 0; i <4 ;i++){
                        if (door[i] == a[xx][yy] && !b[i]) cond = false;
                        if (key[i] == a[xx][yy]) mask = cmask | (1 << i);
                    }
                    if (!cond) continue;
                    if (vis[xx][yy][mask]) continue;
                    node g;
                    vis[xx][yy][mask] =  1 + vis[x][y][cmask];
                    init(g,xx,yy,mask);
                    q.push(g);
                }
            }
        }
        if (ans == 0){
            cout << "The poor student is trapped!\n";
        }else cout << "Escape possible in " << ans << " steps.\n";
    }
}
