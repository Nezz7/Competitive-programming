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
int const MAXN = 1e5 + 9;
LL dp[MAXN][100];
int a[MAXN];
int n;
LL solve(int i, int mn){
    if(i == n) return - mn + 30;
    LL & ret = dp[i][mn];
    if (~ ret) return ret;
    ret = max((LL)a[i] - 30 + solve(i + 1, max(a[i],mn)),(LL)a[i] - 30 - max(a[i],mn) + 30);
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] += 30;
    }
    memset(dp, -1, sizeof dp);
    LL ans = -1e18;
    for(int i = 0; i < n; i++){
        ans = max(ans,solve(i,a[i]));
    }
    cout << ans << endl;
}