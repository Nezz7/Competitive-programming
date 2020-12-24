#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("gcd.in","r", stdin);
    int q;
    cin >> q;
    int ans = 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(r > l) ans = 1;
        else ans = __gcd(ans, l);
        cout << ans << '\n';
    }

    return 0;
}