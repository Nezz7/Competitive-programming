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
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL go (LL x){
    
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL d;
    cin >> d;
    set<LL> primes;
    for(LL i = 2; i * i <= d; i++){
        while(d % i == 0){
            primes.insert(i);
            d/= i;
        }
    }
    primes.insert(d);
    for(auto cur : primes) cout << cur << ' ';
    int q;
    cin >> q;
    while(q--){
        LL u,v;
        cin >> u >> v; 
        if (u < v) swap(u,v);
        if (u == v){
            cout << 1 << endl;
            continue;
        }
        go(u);
    }
}