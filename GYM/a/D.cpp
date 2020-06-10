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
int const MAXN = 4000 + 9;
LL tot = 30 * 60;
LL dp[MAXN][MAXN];
LL a[MAXN], n;
LL solve(int i, int last){
    if (i == n && last == n) return 0;
    if(i == n) return 1e18;
    LL & ret = dp[i][last];
    if( ~ ret) return ret;
    ret = 1e18;
    LL sz = (i - last + 1);
    LL openlast = a[last] + tot - 60;
    LL close =  max(a[i] + 20 + 60,openlast + 120 + sz * 20);
    LL cost = close - openlast;
    ret = min(ret, cost + solve(i + 1, i + 1));
    ret = min(ret,solve(i + 1, last));
    LL openMx = a[i] + tot - (sz) * 20 - 60;
    LL costMx = sz * 20 + 120;
    if(a[last] + tot >= openMx + 20)
    ret = min(ret,costMx + solve(i + 1, i + 1));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0,0);
}