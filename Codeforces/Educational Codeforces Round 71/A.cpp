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
    int T;
    cin >> T;
    while (T--){
        LL b,p,f;
        LL h,c;
        cin >> b >> p >> f;
        cin >> h >> c;
        if (c > h) swap(h,c),swap(p,f);
        b /= 2;
        LL ans = min(b,p);
        b -= ans;
        ans *= h;
        ans += min(f,b) * c;
        cout << ans << endl;
    }
}