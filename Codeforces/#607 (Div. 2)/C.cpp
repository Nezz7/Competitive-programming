#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
int nxt[MAXN];
LL mod = 1e9 + 7;
int main (){

    int T;
    cin >> T;
    while (T--){
        LL   x;
        cin >> x;
        string s;
        cin >> s;
        LL ans = s.size();
        bool cond = true;
        for (LL p = 0; p < x; p++){
            LL r = s[p] - '0';
            r--;
            LL sz = (ans - p - 1 + mod) % mod;
           LL len = ans  + sz;
            while (ans < x && r && cond){
                string g = s.substr(p+1,sz);
                while (ans < x && r){
                 s += g;
                ans = s.size();
                r--;
                }
            }
            if (ans > x) cond = false;

            ans = ((ans + mod )%mod + (r * sz) % mod)%mod;
        }
        cout << ans << "\n";
    }

}
