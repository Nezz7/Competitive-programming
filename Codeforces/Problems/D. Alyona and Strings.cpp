#include <bits/stdc++.h>
using namespace std;
string s, t;
int n, m, k;
int const MAXN = 1005;
int dp[MAXN][MAXN][12][2];
int solve (int i, int j, int k, int l) {
    if (k <0 ) return INT_MIN;
    if (k == 0 && l == 0) return 0;
    if (i == n || j == m) return ((k)?INT_MIN:0);
    int & ret  = dp[i][j][k][l];
    if (ret != -1) return ret;
    ret = 0;
    if (s[i] == t[j]){
        if (l) {
            ret = max(ret, 1 + solve(i+1, j+1, k, l));
        }
        ret = max(ret, 1 + solve(i+1, j+1, k-1, 1));
    }
    return ret = max(ret, max(solve(i + 1, j, k, 0), solve(i, j + 1, k, 0)));
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    cin >> n >> m >> k;
    cin >> s >> t;
    memset( dp, -1, sizeof (dp) ) ;
    cout << solve( 0, 0, k, 0) << "\n";
}
