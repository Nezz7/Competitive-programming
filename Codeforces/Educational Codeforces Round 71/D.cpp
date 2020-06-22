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
int const mod = 998244353 ;
inline LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fact[MAXN];
pair<int,int> a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fact[i] = mul(i,fact[i-1]);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    LL ans = fact[n];
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.pb(a[i].first);
    }
    sort(all(v));
    LL cur = 1;
    LL first = 1;
    for (int i = 0; i < n -1; i++){
        if (v[i] == v[i + 1]){
            cur ++;
        }else {
            first = mul(first,fact[cur]);
            cur = 1;
        }
    }
    first = mul(first,fact[cur]);
    v.clear();
    for(int i = 0; i < n; i++){
        v.pb(a[i].second);
    }
    sort(all(v));
    cur = 1;
    LL second = 1;
    for (int i = 0; i < n -1; i++){
        if (v[i] == v[i + 1]){
            cur ++;
        }else {
            second = mul(second,fact[cur]);
            cur = 1;
        }
    }
    second = mul(second,fact[cur]);
    vector<pair<int,int>> vv;
     for(int i = 0; i < n; i++){
        vv.pb(a[i]);
    }
    sort(all(vv));
    cur = 1;
    LL p = 1;
    for (int i = 0; i < n -1; i++){
        if (vv[i].second > vv[i+1].second) p = 0;
    }
    for (int i = 0; i < n -1; i++){
        if (vv[i] == vv[i + 1]){
            cur ++;
        }else {
            p = mul(p,fact[cur]);
            cur = 1;
        }
    }
    p = mul(p,fact[cur]);
    ans = sub(ans,first);
    ans = sub(ans,second);
    ans = add(ans,p);
    cout << ans << endl;

}