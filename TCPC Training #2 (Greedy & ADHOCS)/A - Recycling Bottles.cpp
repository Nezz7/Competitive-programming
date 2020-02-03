#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5+9;
 double dist (LL x, LL y, LL xx, LL yy){
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}
int vis[MAXN][2][2];
long double dp[MAXN][2][2];
long double a[MAXN][3];
int n;
long double solve (int i,bool A, bool B){
    if (i == n){
        if (A or B) return 0;
        return 1e10;
    }
    long double  & ret = dp[i][A][B];
    if (vis[i][A][B]) return ret;
    vis[i][A][B] = true;
    ret = 1e18;
    if (A == 0) ret = min(ret,a[i][0] + solve(i+1,true,B));
    if (B == 0) ret = min(ret,a[i][1] + solve(i+1,A,true));
    return ret = min(ret,a[i][2] + solve(i+1,A,B));
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    for (int i = 0; i < n;i++){
        LL x, y;
        cin >> x >> y;
        a[i][0] = (dist(ax,ay,x,y)+dist(x,y,tx,ty));
        a[i][1] = (dist(bx,by,x,y)+dist(x,y,tx,ty));
        a[i][2] = 2.0*dist(tx,ty,x,y);
    }
    cout << setprecision(20) << solve(0,false,false);
}
