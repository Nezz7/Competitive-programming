#include <bits/stdc++.h>
using namespace std;
set<char> st;
char a[10][10];
int vis[10][10];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool valid (int x,int y){
    return x >= 0 && y >= 0 && x < 9 && y < 9;
}
int nbr;
void dfs (int x, int y){
    vis[x][y] = 1;
    nbr++;
    for (int i = 0; i < 4;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (vis[xx][yy]) continue;
        if (valid (xx,yy) && a[xx][yy] != '.') st.insert(a[xx][yy]);
        if (valid (xx,yy) && a[xx][yy] == '.') dfs(xx,yy);
    }
}
int main (){
    int n;
    cin >> n;
    while (n--){
        memset(vis,0,sizeof vis);
        int white , black ;
        white  = black = 0;
        for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            cin >> a[i][j];
            if (a[i][j] == 'O') white ++;
            if (a[i][j] == 'X') black ++;
        }
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
                if (!vis[i][j] && a[i][j] == '.'){
                      st.clear();
                      nbr = 0;
                      dfs(i,j);
                      if (st.size() == 1){
                             if (*st.begin() == 'O') white += nbr;
                             else black += nbr;
                      }
                }
        }
    }
     cout << "Black " << black << " White " << white << "\n";
    }
}
