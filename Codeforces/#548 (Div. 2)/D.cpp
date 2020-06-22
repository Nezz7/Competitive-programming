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
const LL mod = 1e9 + 7;
LL add(LL x, LL y){
    x %= mod;
    y %= mod;
    return (x + y) % mod;
}
LL sub(LL x, LL y){
    return ((x - y) % mod + mod) % mod;
}
LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e & 1)return b * 1ll * fast(b, e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

 LL inv(LL x){
    return fast(x ,mod - 2);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int m;
    cin >> m;
    LL ans = 0;
    for(LL i = 2; i <= m; i++){
        LL x = inv(i);
        LL no = sub(1,x);
        LL s2 = inv(no * no);
        LL s1 = inv(no);
        LL s = sub(s2, s1);
        s = mul(s, no);
        ans = add(ans,s);
        LL to = mul(fast(x,m),m);
        ans = add(ans,to);
    }
    ans = add(ans,inv(m));
    cout << ans << endl;
}