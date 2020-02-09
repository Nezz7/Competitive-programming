#include <bits/stdc++.h>
using namespace std;
pair<int,int> p[1005][1005];
int vis[1005][1005];
vector<string> out;
    int ca, cb, n;
void print (int a , int b){
    int x = p[a][b].first;
    int y = p[a][b].second;
    if (a == x && y == b) return;
    if (a == x && b == 0){
        out.push_back("empty B");
    }
    if (y == b && a == 0){
        out.push_back("empty A");
    }
    if (a == x && b == cb){
        out.push_back ("fill B");
    }
    if (y == b && a == ca){
        out.push_back ("fill A");
    }
    int xx = min (ca, x+y);
    int yy = x+y  - xx;
    if (xx == a && yy == b){
        out.push_back("pour B A");
    }
     yy = min (cb, x+y);
     xx = x+y  - yy;
    if (xx == a && yy == b){
        out.push_back("pour A B");
    }
    print(x,y);
}
int main (){
    while(cin >> ca >> cb >> n){
        out.clear();
        queue<pair<int,int>> q;
        for (int i  = 0; i <= ca; i++)
            for (int j = 0; j <= cb ; j++)
                vis[i][j] = false;
        q.push({0,0});
        p[0][0] = {0,0};
         int x = 0 ;
        while (!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            if (b == n) {
                x = a;
                break;
            }
            if (vis[a][b]) continue;
            vis[a][b] = true;
            if (!vis[a][cb] && cb!=b){
                p[a][cb] = {a,b};
                q.push({a,cb});
            }
            if (!vis[ca][b] && ca!=a){
                p[ca][b] = {a,b};
                q.push({ca,b});
            }
            if (!vis[0][b] && a ){
                p[0][b] = {a,b};
                q.push({0,b});
            }
            if (!vis[a][0] && b){
                p[a][0] = {a,b};
                q.push({a,0});
            }
            int x = min(ca, a+b);
            int y = a+b - x;
            if (!vis[x][y] && x !=a && y!= b){
                p[x][y] = {a,b};
                q.push ({x,y});
            }
             y = min (cb, a+b);
             x = a + b - y;
            if (!vis[x][y] && a!=x && y!=b){
                p[x][y] = {a,b};
                q.push ({x,y});
            }
        }
        print(x,n);
        reverse(out.begin(),out.end());
        for (auto cur : out){
            cout << cur << "\n";
        }
        cout << "success\n";
    }
}
