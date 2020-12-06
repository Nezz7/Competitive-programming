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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL p, q;
        cin >> p >> q;
        if(p % q){
            cout << p << endl;
            continue;
        }
        LL ans = 1;
        LL x = q;
        for(LL i = 2; i * i <= x; i++){
            while(x % i == 0){
                x /= i;
            }
            LL tmp = p;
            while(tmp % i == 0){
                tmp /= i;
                if(tmp % q ) ans = max(ans, tmp);
            }
        }
        LL tmp = p;
        while(x > 1 && tmp % x == 0){
            tmp /= x;
            if(tmp % q ) ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
}