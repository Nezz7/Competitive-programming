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
LL h, c, t;
LD f(LL x){
    x = 2 * x + 1;
    LL a = (x + 1)/ 2;
    LL b = x / 2;
    return abs((a * h + b * c ) / (LD) x - t) ;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> h >> c >> t;
        LL l = 0, r = 1e9;
        LD ans = 1e18;
        LL out;
        if(ans > abs((h + c)/ 2.0L - t)){
            ans = abs((h + c)/ 2.0L - t);
            out = 2;
        }
        while((r - l) > 3){
            LL m1 = l + (r - l) / 3;
            LL m2 = r - (r - l) / 3;
            LD f1 = f(m1);
            LD f2 = f(m2);
            if(f1 > f2){
                l = m1;
            }else r = m2;
        }
        for(LL i = l; i <= r; i++){
            if(ans > f(i)){
                out =  i * 2 + 1;
                ans = f(i);
            }
        }
        cout << out << endl;
    }
}