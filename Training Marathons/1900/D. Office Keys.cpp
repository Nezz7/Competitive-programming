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
int const MAXN = 2000 + 9;
LL dp[MAXN][MAXN];
LL a[MAXN], b[MAXN];
LL n, k, p;
LL solve(int i , int j){
    if(i == n) return 0;
    if(k == j) return 1e18;
    LL & ret = dp[i][j];
    if( ~ ret ) return ret;
    ret = solve(i, j + 1);
    ret = min(ret, max(abs(a[i] - b[j]) + abs(b[j] - p),solve(i + 1, j + 1)));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> k >> p;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int j = 0; j < k; j++)
        cin >> b[j];
    memset(dp, -1, sizeof (dp));
    cout << solve (0,0);
}