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
LL const mod = 998244353;
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
LL fact[MAXN], a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < 2*n; i++)
        cin >> a[i];
    
    sort(a, a + 2*n);
    LL sum = 0;
    for(int i = 0; i < n; i++)
        sum -= a[i];
    for(int i = n; i < 2*n; i++)
        sum += a[i];
    fact[0] = 1;
    sum %= mod;
    for(int i = 1; i < MAXN; i++)
        fact[i] = mul(fact[i - 1] , i); 
    LL bin = mul(fact[2*n], inv(mul(fact[n], fact[n])));
    cout << mul(bin, sum); 
}