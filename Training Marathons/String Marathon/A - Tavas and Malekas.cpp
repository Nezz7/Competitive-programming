#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 7;
int const mod = 1e9 + 7;
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e&1)return b * 1ll * fast(b,e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}
vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int len = s.size();
    int a[m];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    LL ans = 1;
    vector<int> z = z_function(s);
    for(int i = 0; i < m - 1; i++){
        if(a[i+1] - a[i] >= len) ans = mul(ans,fast(26,a[i+1] - a[i] - len));
        else if (a[i] + len - a[i+1] > z[a[i+1] - a[i]]) ans = 0;
    }
    if(m && n - a[m - 1] + 1> len ) ans = mul(ans,fast(26,n - a[m - 1] - len + 1));
    if(m && a[0] > 1) ans = mul(ans,fast(26,a[0] - 1));
    if(m == 0) ans = fast(26,n); 
    cout << ans;
}