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
int a[MAXN][MAXN];
int dist (int x,int y, int a, int b){
    return (abs(a - x) + abs(y - b));
}
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int x = 1, y = 1;
int n;
bool cond = false;
void read(int op){
    string s;
    cin >> s;
    if(s == "YES"){
        x += dx[op];
        y += dy[op];
        a[x][y] = 1;
        cond = true;
    }
}
bool valid(int x, int y){
    return x >= 1 &&  x <= n && y >= 1 && y <= n;
}
int cnt = 0;
void query(int x, int y, int a, int b,int op){
        if(!valid(x,y) or !valid(a,b)) return;
        cnt++;
        cout << "? " << x << ' ' << y <<  ' ' << a << ' ' << b << endl;
        cout.flush();
        read(op);
}
bool ans = false;
string get(int x, int y){
    if(x == n && y == n) return "";
    if(valid(x + 1, y) && a[x + 1][y]) return  "D" + get(x + 1, y);
    if(valid(x, y + 1) && a[x][y + 1]) return "R" + get(x , y + 1);
    return "";
}
int main(){
    cin >> n;
    a[1][1] = 1;
    a[n][n] = 1;
   while (cnt < 4*n){
        if(x == n && y == n) break;
        cond = false;
        if(dist(x + 1, y, n, n) >= n - 1){
            query(x + 1, y, n, n,0);
        }
        if(cond) continue;
        if(dist(x , y + 1, n, n) >= n - 1){
            query(x , y + 1, n, n,1);
        }
        
        if(!cond) break;
    }
    x = n, y = n;
    while (cnt < 4*n){
        cond = false;
        if(dist(1 , 1, x, y - 1) >= n - 1){
            query(1, 1, x, y - 1,3);
        }
        if(cond) continue;
      
        if(dist(1, 1, x - 1, y) >= n - 1){
            query(1, 1, x - 1, y,2);
        }
        if(!cond) break;
    }
    cout << "! " << get(1,1) << endl;
    cout.flush();
 
}