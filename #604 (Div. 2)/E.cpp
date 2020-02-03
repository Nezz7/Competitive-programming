#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MOD = 998244353;
int const MAXN = 2e6+9;
LL mypow(LL x, LL y,LL m){
    if (y == 0)
        return 1;
    LL p = mypow(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n ;
    cin >> n;
    LL a[n];
    LL pref[n+1];
     pref[0] = 100;
     LL ans  = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pref[i+1] = (pref[i] * a[i]) % MOD;
    }
    for (LL i = 0; i <= n;i++){
        ans += (((pref[i]*mypow(mypow(100,i+1,MOD),MOD-2,MOD))% MOD ) * (i+1))%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
