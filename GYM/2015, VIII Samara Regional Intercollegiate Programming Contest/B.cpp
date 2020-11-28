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
    LL n, p, x;
    cin >> p >> n >> x;
    LL cur_pos = 0;
    LL ans = x / p;
    LL f = x - ans * p;
    LL s = min(p * (ans + 1), n) - x + 1;
    LL t = 1 + abs(ans - n/p) * 2+ abs(x % p - n % p); 
    cout << ans + min({f, s, t});
}