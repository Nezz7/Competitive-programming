#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[5000];
int dp[3000][3000][2];
int  solve (int i, int r,int l){
    if (i == m ){
        if (r == 0 && l == 1) return 1;
        return 0;
    }
    int &ret = dp[i][r][l];
    if (ret != -1) return ret;
    ret = 0;
    for (int j = 0; j <= min(a[i],m) ; j++ ){
        if (j == 0)
            ret = solve (i+1,r,l);
        else ret = solve (i+1,((j*i)+r)%m,1);
        if (ret) break;
    }
    return ret;

}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie(0), cout. tie(0);
    memset(dp,-1,sizeof dp );
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++){
         int x;
         cin >> x;
         a[x % m] ++;
    }
    bool cond = solve (0,0,0);
    if (cond )
        cout << "YES\n";
    else cout << "NO\n";
}
