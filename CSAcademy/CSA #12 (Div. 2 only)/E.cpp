#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int const MOD  = 1e9 + 7;
int z[MAXN];
void z_function(string s) {
    int n = (int) s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    z[0] = n;
}
bool get_cond (string a, string b){
   if (sz(a) < sz(b)) return true;
   if (sz(a) > sz(b)) return false;
   return a <= b;
}
LL my_pow (LL x, LL b){
   if (b == 0) return 1;
   LL a = my_pow(x,b/2);
   if (b&1) return ((((a * a)%MOD) * x)%MOD);
   return (a * a)%MOD;
}
LL get(string s){
   LL p = 1;
   LL ret = 0;
   for (int i = sz(s) - 1; i >= 0; i--){
      ret +=  p * (s[i] - '0');
      ret %= MOD;
      p *= 10;
      p%= MOD;
   }
   ret ++;
   ret %= MOD;
   return ret;
}
int main(){
   ios_base::sync_with_stdio (0),cin.tie(0);
   string n, m;
   cin >> n >> m;
   int k = m.size();
   z_function (m);
   string str;
   LL ans = 0;
   for (int i = 0; i < sz(m);i++){
      if (z[i]+ i == k){
         if (2*k - z[i] < n.size()){
            ans++;
            ans %=MOD;
         }else if (2*k - z[i] == n.size()){
            string str = m + m.substr(z[i],sz(m) - z[i]);
           if (get_cond(str,n)) ans++;
           ans %=MOD;
         }
      }
   }
    str = m + m;
   if(get_cond(str,n)){
      ans++;
      ans%= MOD;
   }
   ans %=MOD;
   if (sz(n) <= 2 *sz(m)){
      cout << ans << endl;
      return 0;
   }
   LL p = 1;
   int j = 1;
   for (int i = 2 * sz(m)  + 1; i < sz(n); i++){
         ans += my_pow(10,j);
         ans %=MOD;
         j++;
   }
   if (p >= 10)
      ans += p;
   ans %= MOD;
   str = n;
   string y = str.substr(sz(n) - sz(m),sz(m));
   if (y < m){
      for (int i =sz(n) - sz(m) - 1; i>= 0; i--){
          if (str[i] == '0') continue;
          str[i] --;
          break;
      }
   }
   y = str.substr(0,sz(m));
   if (y < m){
      cout << ans << endl;
      return 0 ;
   }
   string x = "";
   bool cond = false;
   if (y == m) cond = true;
   for (int i = sz(m) ; i < sz(n) -(int) sz(m); i++)
      if (cond)
      x+= str[i];
      else x+='9';
   ans+= get(x);
   ans%=MOD;
   cout << ans << endl;
}