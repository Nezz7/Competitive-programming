#include <bits/stdc++.h>
#define LL long long int
using namespace std;
LL dp[1000][1000];
LL C (int n, int k){
    if (k == 0 or k == n) return 1;
    if (dp[n][k]!=-1) return dp[n][k];
    return dp[n][k] = C(n-1,k-1)+C(n-1,k);
}
int main (){
    for (int i = 0; i < 51;i++)
        for (int j = 0; j < 51; j++)
        dp[i][j] = -1;
    int T;
    cin >> T;
    while (T--){
        int c;
        cin >> c;
         double p;
        cin >> p;
        int n  = 2*c - 1;
         double ans =0;
        for (int k = c; k <= n; k++)
         ans += C(n,k)*pow (p,k)*pow(1-p,n-k);
        printf("%.2f\n",ans);
    }

}
