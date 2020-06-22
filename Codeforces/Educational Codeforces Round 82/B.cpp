#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
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
        LL x, g, b;
        cin >> x  >> g >> b;
        LL a = (x + 1) / 2;
        LL c = (a / g);
        LL ans = (a / g) *  (g + b);
        if (a % g) ans += a % g;
        else ans -= b,c--;
        a = x - a;
        if (b * c < a) ans+=( a - b *c);
        cout << ans << endl; 
    }
}