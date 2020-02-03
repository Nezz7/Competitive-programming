#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e3;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n;
char a[MAXN][MAXN];
int vis[MAXN][MAXN];
bool valid (int i,int j){
        return i>=0 && i<n && j>=0 && j<n && a[i][j]!='D';
}
int main (){
    cin>>n;
    queue<pair<pair<int,int>,int>>q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
                cin>>a[i][j];
                if (a[i][j] == 'S')
                q.push({{i,j},0});

        }
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int path = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (valid(xx,yy) &&  !vis[xx][yy]){
                if (a[xx][yy] == 'X'){
                    cout<<path+1;
                    return 0;
                }
                q.push({{xx,yy},path+1});
            }
        }
    }
    cout<<-1;

}
