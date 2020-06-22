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
int const MAXN = 2e5 + 9;
LL const mod = 998244353;
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e & 1)return b * 1ll * fast(b, e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

 LL mod_inv(LL x){
    return fast(x ,mod - 2);
}

LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fact[MAXN], inv[MAXN];
int a[MAXN];
int have[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bool bad = false;
    LL cnt = 0;
    for(int i = 0; i < n; i++){
       if(a[i] == -1) {cnt++;continue;}
       if(i - 2 >= 0 && a[i - 2] == a[i]) bad = true;
       if(i + 2 < n  && a[i + 2] == a[i]) bad = true;
   }
    if(bad){
        cout << 0;
        return 0;
    }
    LL ans = 1;
    for(int i = 0; i < n; i++) have[i] = k;
     for(int i = 0; i < n; i++){
       if(a[i] == -1) continue;
       if(i - 2 >= 0) have[i - 2] --;
       if(i + 2 < n) have[i + 2] --;
     }
    for(int i = 0; i < n; i++){
        if(a[i] != -1) continue;
        if(i + 2 < n) have[i + 2]--;
        cout << have[i] << endl;
        ans = mul(ans,have[i]);
    }
    cout << ans << endl;
}