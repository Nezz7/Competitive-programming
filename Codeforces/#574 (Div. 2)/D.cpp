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
inline LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL size[20];
vector<int> get(int x){
    vector<int> ret;
    while(x > 0){
        ret.pb(x % 10);
        x /= 10;
    }
    size[sz(ret)] ++;
    return ret;
}
LL p[MAXN];
vector<vector<int>> a;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.pb(get(x));
    }
    p[0] = 1;
    for(int i = 1; i < 20; i++){
        p[i] = mul(10, p[i - 1]);
    }
    LL ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < 12; j++){
            for(int k = 0; k < sz(a[i]); k++)
                if(k == 0) ans = add(ans,mul(size[j],a[i][k]));
                else {
                    if(j >= k){
                        ans = add(ans,mul(size[j],mul(a[i][k],p[k * 2])));
                    }else ans = add(ans,mul(size[j],mul(a[i][k],p[j + k])));
                }
                for(int k = 0; k < sz(a[i]); k++)
                    if(k == 0) ans = add(ans,mul(size[j],a[i][k]*10));
                    else {
                    if(j >= k + 1){
                        ans = add(ans,mul(size[j],mul(a[i][k],p[k* 2 + 1])));
                    }else ans = add(ans,mul(size[j],mul(a[i][k],p[j + k])));
                }
            }
        }
    cout << ans << endl;
    
}