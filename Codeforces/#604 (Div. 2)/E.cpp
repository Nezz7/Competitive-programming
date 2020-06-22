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
int const mod = 998244353;
inline LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e&1)return b * 1ll * fast(b,e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

inline LL inv(LL x){
    return fast(x,mod - 2);
}
int p[MAXN],pre[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i] = mul(p[i],inv(100));
    }
    pre[0] = p[0];
    for(int i = 1; i < n; i++){
        pre[i] = mul(p[i],pre[i - 1]);
    } 
    LL ans = 1;
    for(int i = 0; i < n - 1; i++){
        ans = add(ans, pre[i]);
    }
    ans = mul(ans ,inv(pre[n - 1]));
    cout << ans << endl;
}