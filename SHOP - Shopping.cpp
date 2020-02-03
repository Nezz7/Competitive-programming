#include <bits/stdc++.h>
using namespace std;
int dx[] ={0,0,-1,1};
int dy[] ={1,-1,0,0};
int n, m;
char a[60][60];
int dist[60][60];
struct node{
    int cost;
    int x,y;
    node(){}
    node(int i, int j, int c){
        cost = c;
        x = i;
        y = j;
    }
    bool operator < (const node & n) const{
        return cost > n.cost;
    }

};
int get_w (int x, int y){
    if (a[x][y] == 'D') return 0;
    return a[x][y] - '0';
}
bool valid (int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m;
}
int main (){
    while (cin >> n >> m  && n && m){
            swap(n,m);
        int xs,ys,xe,ye;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                    cin >> a[i][j];
                    if (a[i][j] == 'S') xs = i , ys = j;
                    if (a[i][j] == 'D') xe = i , ye = j;
                    dist[i][j] = 1e9;
            }
      priority_queue<node> pq;
      pq.push(node(xs,ys,0));
      dist[xs][ys] = 0;
      while (!pq.empty()){
            node u = pq.top();
            pq.pop();
            if (dist[u.x][u.y] > u.cost) continue;
            for (int i = 0; i < 4; i++){
                int xx = u.x + dx[i];
                int yy = u.y + dy[i];
                if (valid (xx,yy) && a[xx][yy]!='X' && dist[xx][yy] > dist[u.x][u.y] + get_w(xx,yy)){
                    dist[xx][yy] = dist[u.x][u.y] + get_w(xx,yy);
                    pq.push(node(xx,yy,dist[xx][yy]));
                }
            }
      }
        cout << dist[xe][ye] << "\n";
    }
}
