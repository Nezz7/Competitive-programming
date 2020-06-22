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
int const MAXN = 2e6 + 9;
int occ[MAXN];
LL  inv[MAXN];
LL const mod = 998244353;
vector<vector<int>>g;
LL mul (LL a, LL b){
    return ((a % mod) * (b % mod)) % mod ;
}
LL exp (LL a, LL b){
    if (b == 0) return 1LL;
    LL x = exp(a,b/2);
    if (b%2) return  mul(x,mul(x,a));
    return  mul(x,x);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    LL a = 1,  b = 1;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int x;
            cin >> x;
            occ[x]++;
            g[i].push_back(x);
        }
    }
    LL ans = 0;

    for (int i = 0; i < MAXN; i++) inv[i] = exp(i,mod - 2);
    for (int i = 0; i < n; i++){
        for (auto cur : g[i]){
            LL k = sz(g[i]);
            ans = (ans + mul(  mul(inv[n],inv[k]) ,  mul(occ[cur],inv[n]) ) )% mod;
        }
    }
    cout << ans ;

}