#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5 + 9;
LL dp[MAXN][4];
LL a[MAXN][3];
int n;
LL solve (int i, int l){
    if (i == n) return 0;
    LL & ret = dp[i][l];
    if (ret != -1) return ret;
    ret = 0;
    for (int j = 0; j < 3; j++){
        if (j == l) continue;
        ret = max(ret,a[i][j] + solve(i+1,j));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    cout << solve(0,3);

}
