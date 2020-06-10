#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
LL const mod = 1e9 + 7;
pair<int,int> black[MAXN];
LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e & 1)return b * 1ll * fast(b, e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

 LL inv_mod(LL x){
    return fast(x ,mod - 2);
}
LL fact[MAXN],inv[MAXN],dp[MAXN];
LL C(LL n, LL k){
    LL ret = fact[n];
    LL d = mul(inv[n - k], inv[k]);
    return mul(ret,d);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> black[i].first >> black[i].second;  
    }
    fact[0] = 1;
    inv[0] = inv_mod(fact[0]);
    for(int i = 1; i < MAXN; i++){
        fact[i] = mul(i,fact[i - 1]);
        inv[i] = inv_mod(fact[i]);
    }
    black[n].first = h;
    black[n].second = w;
    n++;
    sort(black, black + n);
    for(int i = 0; i< n; i++){
        int x = black[i].first;
        int y = black[i].second;
        dp[i] = C(x + y - 2, x - 1);
        for(int j = 0; j < i; j++){
            int a = black[j].first;
            int b = black[j].second;
            if(b <= y){
                LL tmp = dp[j];
                LL nbr = C(x + y - a - b, y - b);
                dp[i] = sub(dp[i], mul(tmp, nbr));
            }
        }
    }
    cout << dp[n - 1] << endl;
}