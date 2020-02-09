#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 4e5+5;
int pref[MAXN][62];
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL ans = 0;
    LL mod = 1e9+7;
    for (int i = n - 1; i >= 0; i--){
        for (LL j = 0; j <= 60 ;j ++){
            LL bit = ((1LL<<j) & a[i])>>j;
            pref[i][j] = pref[i+1][j] + bit;
            LL x = n - 1 - i;
            if (bit){
              ans =    (((1LL << j)%mod) * (x - pref[i+1][j])%mod)%mod + ans % mod;
              ans %= mod;
            }else {
                ans =    (((1LL << j)%mod) * (pref[i+1][j])%mod)%mod + ans % mod;
              ans %= mod;
            }

        }
    }
    cout << ans;

}
