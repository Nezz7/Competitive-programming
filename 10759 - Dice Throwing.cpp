#include <bits/stdc++.h>
#define LL  long long int
using namespace std;
LL dp[25][200];
int n , x;
LL solve (int i, int sum){
    if (i == 0) return sum >= x;
    LL & ret = dp[i][sum];
    if (ret != -1) return ret;
    ret = 0;
    for (int k = 1; k < 7 ; k++){
        ret +=  solve(i-1 ,sum + k);
    }
    return ret;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie(0) ; cout.tie (0);
    while (cin >> n >> x){
        if (n == 0 && x == 0) break;
        memset(dp, -1, sizeof dp);
        LL a = solve(n, 0);
        LL b = 1;
        for (int i = 0; i < n; i++)
            b*=6;
        LL g = __gcd(a,b);
        a/=g;
        b/=g;
        if (a == 0) cout << 0 << "\n";
        else if (a == 1 && b == 1) cout << 1 <<"\n";
        else cout << a << "/" << b << "\n";
    }
}
