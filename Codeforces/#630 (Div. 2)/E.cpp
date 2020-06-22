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
LL const mod = 998244353;
LL mul (LL a, LL b){
  a %= mod;
  b %= mod;
  return (a * b) % mod;
}
LL add (LL a, LL b){
  return (a + b) % mod;
}
LL fast(LL a, LL b){
  if(b == 0) return 1;
  LL x = fast(a, b / 2);
  if(b & 1) return mul(a, mul(x, x));
  return mul(x, x);
}
int main(){
  ios_base::sync_with_stdio (0),cin.tie(0);
  LL n, m, r, l;
  cin >> n >> m >> l >> r;
  LL all = n * m;
  LL it = r - l + 1;
  if(all & 1){
    cout << fast(it, n * m) << endl;
    return 0;
  }
  LL a = l, b = r;
  if(a & 1) a++;
  if(b & 1) b--;
  LL even =  (b - a + 2) / 2;
  LL odd = it - even;
  LL ans = add(fast(even + odd, n * m),fast(even - odd, n * m));
  ans = mul (ans, fast(2, mod - 2));
  cout << ans << endl;

}