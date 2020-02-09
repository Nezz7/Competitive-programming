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
int const MAXN = 2010;
LL a[MAXN],sum[MAXN];
LL get (LL x){
    int p = x/10;
    int d = x%10;
    if (d < 5) return p * 10;
    return (p + 1) * 10;
}
LL dp[MAXN][25];
LL inf = 1e15;
int n,d;
LL solve (int i,int d){
    if (i == n){
        if (d == 0) return 0;
        return inf;
    }
    if ( d <= 0) return inf;
    LL & ret = dp[i][d];
    if (ret != -1) return ret;
    ret =  inf;
    for (int k = i ; k < n; k++){
        ret = min(ret, solve(k + 1,d - 1) + get(sum[k + 1] - sum[i]));
    }
    return ret;
 } 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sum[0] = 0;
    for (int i = 0; i < n; i++){
        sum[i + 1] = sum[i] + a[i];
    }
    LL ans = inf;
    for (int i = 1; i<= d + 1; i++)
        ans = min(ans,solve(0,i));
    cout << ans << endl;
}