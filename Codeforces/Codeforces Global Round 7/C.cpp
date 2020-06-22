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
int mod = 998244353;
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n >> k;
    LL p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    LL mx = 0;
    for (int i = 0; i < k; i++){
        mx += n - i;
    }
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(p[i] >= n - k + 1){
            v.pb(i);
        }
    }
    LL ans = 1;
    for (int i = 1; i < sz(v); i++){
            ans = mul(ans,v[i] - v[i-1]);
        
    }
    cout << mx << ' ' << ans << endl;
}