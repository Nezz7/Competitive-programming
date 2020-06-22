#include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long int
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 LL const mod = 1e9 + 7;
 LL mul (LL a, LL b){
    a %= mod;
    b %= mod;
    return (a * b) % mod;
 }
 LL po (LL a, LL b){
    if (b == 0) return 1;
    LL x = po(a,b/2);
    if (b&1) return mul(x,mul(x,a));
    return mul(x,x);
 }
 bool is_prime (LL x){
    if (x == 1) return false;
    for (LL i = 2; i *i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n , x;
    cin >> x >> n;
    vector<pair<LL,LL>> v;
    if (is_prime(x))  v.push_back({x,1});
    else {
        for (LL i = 2; i*i <= x; i++){
              int cnt = 0;
              while (x % i == 0){
                   x/= i;
                   cnt++;
              }
              if (cnt)
              v.emplace_back(i,cnt);
        }
        if (x > 1) v.push_back({x,1});
    }
    LL ans = 1;
    for (auto cur : v){
        LL p = 1;
        vector<pair<LL,LL>> a;
        while (p <= n && p > 0){
            LL last = p;
             LL lg = log10(p) + log10(cur.first);
            p*=cur.first;
            if (p <= n && p > 0 && p > last && lg <= 18)
            a.emplace_back(n/p,p);
            else break;
        }
        LL last = 0;
        for (int i = sz(a) - 1; i >=0; i--){
            LL f = a[i].first;
            LL s = a[i].second;
            if (last !=0)
            ans = mul(ans,po(s, last - f));
            else
            ans = mul(ans,po(s,  f));
            last = f;
        }
    }
    cout << ans;
 }
