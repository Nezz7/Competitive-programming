#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e6+5;
struct nd {
    int x,y,sum1,sum2;
    const
};
    int n, m;
map<nd,int> dp;
map<nd,int> vis;
bool valid (int i,int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}
int a[90][90];
int b[90][90];
int solve (int i,int j,int sum1,int sum2){
    nd cur;
    cur.x =i;
    cur.y =j;
    cur.sum1 =sum1;
    cur.sum2 =sum2;
    if (i == n - 1 && j == m - 1) return min (abs(sum1+a[i][j]-sum2-b[i][j]),abs(sum1+b[i][j]-sum2-a[i][j]));
    if (vis[cur]) return dp[cur];
    int & ret = dp[cur];
    vis[cur] = 1;
    ret = 1e9;
    if (valid(i+1,j)) ret = min(solve(i+1,j,sum1+a[i][j],sum2+b[i][j]),solve(i+1,j,sum1+b[i][j],sum2+a[i][j]));
    if (valid (i,j+1)) ret = min(ret,min(solve(i,j+1,sum1+a[i][j],sum2+b[i][j]),solve(i,j+1,sum1+b[i][j],sum2+a[i][j])));
    return ret;

}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin  >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    cout << solve (0,0,0,0);
}
