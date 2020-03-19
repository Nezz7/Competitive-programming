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
int const MAXN = 1e3 + 9;
int n,m;
LL const mod = 998244353;
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    LL ans = 1;
    for (int i = 0; i < n + m; i++){
        ans = mul(ans,2);
    }
    cout << ans;
}