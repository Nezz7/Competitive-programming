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
LL a,b,q;
LL g;
LL get(LL x){
    LL mx = max(a,b);
    LL y = a * b / g;
    LL ret = (x / y) * mx;
    if(x % y < mx) ret+= (x % y) + 1;
    else ret+= mx;
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> q;
        g = __gcd(a,b);
        while(q--){
            LL l,r;
            cin >> l >> r;
            LL tot =  r - l + 1 - (get(r) - get( l- 1));
            cout << tot << ' ' ; 
        }
        cout << endl;
    }
}