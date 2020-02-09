#include <bits/stdc++.h>
#define LL  long long int
#define LD  double
using namespace std;
LD dp[10][20][20];
int vis[10][20][20];
int n , x;
int p[20][20];
string team [20];
LD Get (int n, int x);
LD solve (int n, int x, int y){
    if (x == y) return 0.0;
    bool cond = false;
    int pp = 2;
    for (int i = 1; i <n ;i++){
        int a = (x-1)/(pp);
        int b = (y-1)/(pp);
        pp*=2;
        if (a == b) cond = true;
    }
     int a = (x-1)/(pp);
     int b = (y-1)/(pp);
    if (a != b or cond ) return 0.0;
    if (n == 1) return (p[x][y]/100.0);
    LD & ret = dp[n][x][y];
    if (vis[n][x][y]) return ret;
    vis[n][x][y] = true;
    LD L = 0;
     for (int i = 1 ; i <= 16; i++)
        L += solve(n-1,y,i);
    LD R = 0;
     for (int i = 1 ; i <= 16; i++)
        R += solve(n-1,x,i);
    return ret = (p[x][y] / 100.0 ) * L * R;
}
LD Get (int n, int x){
    LD ret = 0;
    for (int i = 1 ; i <= 16; i++){
        LD  c =solve(n,x,i);
        ret += c;
    }
    return ret;
}
int main (){
   for (int i = 1; i <= 16; i++)
        cin >> team[i];
   for (int i = 1; i <= 16; i++)
        for (int j = 1; j <= 16; j++)
            cin >> p [i] [j];
   memset(vis, false , sizeof vis );
   for (int i = 1; i <= 16; i++){
        printf("%-10s p=%.2f%\n",team[i].c_str(),Get(4,i)*100);
   }
}
