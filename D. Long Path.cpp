#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e3 + 9;
int const MOD = 1e9 + 7;
LL dp[MAXN];
LL sum[MAXN];
int main (){
    int n;
    cin >> n;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        if (a[i] == i + 1) dp[i] = 2;
        else dp[i] = (2 + sum [ i ] - sum[a[i]-1] + MOD)%MOD;
        sum[i + 1] = (dp[i]  + sum[i]) % MOD;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans  + dp[i] )% MOD;
    cout << ans << "\n";


}
