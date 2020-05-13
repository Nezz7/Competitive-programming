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
char a[MAXN][MAXN];
LL dist[MAXN][MAXN];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m,t;
bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
char rev(char c){
    if(c == '1') return '0';
    return '1';
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            dist[i][j] = 1e18+9;    
            bool good = false;
            for(int k  = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if( valid (x,y) && a[x][y] == a[i][j]) good = true;
            }
            if(good){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(valid(xx,yy) && dist[xx][yy] > dist[x][y] + 1){
                dist[xx][yy] = dist[x][y] + 1;
                q.push({xx,yy});
            }
        }
    }
    while(t--){
        LL x,y,p;
        cin >> x >> y >> p;
        x--,y--;
        if(p < dist[x][y]) cout << a[x][y] << endl;
        else{ p -= dist[x][y], p = p & 1;
            if(!p) cout << a[x][y] << endl;
            else cout << rev(a[x][y]) << endl;
        }
    }
}