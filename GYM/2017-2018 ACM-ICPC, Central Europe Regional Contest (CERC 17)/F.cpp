#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e7 + 9;
LL mod;
LL g[MAXN];
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e&1)return b * 1ll * fast(b,e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

inline LL inv(LL x){
    return fast(x,mod-2);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n,p,r;
    cin >> n >> p >> r;
    mod = p;
    if (n/p > 1){
        if (!r)
        cout << p << " " << 1;
        else cout << -1 << " " << -1;
        return 0;
    }
    if( n / p < 1 && r == 0){
        cout << -1 <<  " " << -1;
        return 0;
    }
    if( n / p == 1 && r == 0){
        for( int i = 2; i <= n; i++){
            if ( i  != p ){
                cout << i << " " << i -1;
                return 0;
            }
        }       
        cout << -1 << " " << -1;
        return 0;
    }
    LL fact = 1;
    for(int i = 1; i <= n; i++){
        if (n/p == 1 && i == p ) continue;
        fact = mul(fact,i);
    } 
    if(n / p == 1){
        LL x = mul(inv(fact),r);
        if(x < p){
            cout << p << " " << x;
            return 0;
        }
        cout << -1 << " " << -1;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        LL cur = mul(fact ,inv(i));
        LL x = mul(inv(cur),r);
        if (x == 0) x = p;
        if ( x < i){
            cout << i << " " << x;
            return 0;
        }
    }
    cout << -1 << " " <<  -1 ;
}