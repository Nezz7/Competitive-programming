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
LL a[MAXN];
LL dp[MAXN][3];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[1][0] = r3 + a[1] * r1;
    dp[1][1] = min(r2, a[1] * r1 + r1);
    LL tmp = 0;
    for(int i = 2; i <= n; i++){
        dp[i][0] = r3 + a[i] * r1 + dp[i - 1][0] + d;
        dp[i][1] = dp[i - 1][0] + d + min(r2, a[i] * r1 + r1);

        tmp = dp[i - 1][1] + d + r3 + a[i] * r1 + r1 + 2 * d;
        dp[i][0] = min(tmp, dp[i][0]);

        tmp = dp[i - 1][1] + d + a[i] * r1 + r1 + d + r1 + d + r1;
        dp[i][0] = min(tmp, dp[i][0]);

        tmp = dp[i - 1][1] + d + r2 + d + r1 + d + r1;
        dp[i][0] = min(tmp, dp[i][0]);


        tmp = dp[i - 1][1] + d + r1 * a[i] + r1 + d + r1 + d;
        dp[i][1] = min(tmp, dp[i][1]);

        tmp = dp[i - 1][1] + d + r2 + d + r1 + d;
        dp[i][1] = min(tmp, dp[i][1]);
    }
    LL ans1 = dp[n][0];
    LL ans2 = dp[n - 1][1] + d + a[n] * r1 + r3 + d + r1;
    cout << min(ans1, ans2) << endl;
}
