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
LL mod = 1e9 + 7;
LL add (LL a, LL b){
    return ((a + b) % mod + mod) % mod;
}
LL sub (LL a, LL b){
    return ((a - b) % mod + mod) % mod;
}
LL mul(LL a, LL b){
    a  %= mod;
    b  %= mod;
    return (a * b) % mod;
}
LL fast(LL a, LL b){
    if (b == 0) return 1;
    LL x = fast(a, b / 2);
    LL ret = mul(x, x);
    if( b & 1) return mul(a, ret);
    return ret;
}
int is_prime[MAXN],u[MAXN];
int d[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    is_prime[1] = 1;
    for(int i = 1; i < MAXN; i++)
        u[i] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!is_prime[i]){
            u[i] = -1;
            is_prime[i] = i;
            for(int j = 2 * i; j < MAXN; j += i)
                is_prime[j] = i, u[j] = (j % (i * 1LL * i)) ? - u[j] : 0; 
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(LL j = 1; j * j <= x; j++){
            if(x % j == 0){
                LL a = x / j;
                if(a != j) d[a]++;
                d[j]++;
            }
        }
    }
    LL ans = sub(fast(2, n), 1);
    for(int i = 2; i < MAXN; i++){
        if(d[i] == 0) continue;
        LL x = sub(fast(2, d[i]), 1);
        ans = add(ans,u[i] * x);
    }
    cout << ans << endl;
}