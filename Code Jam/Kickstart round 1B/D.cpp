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
int const MAXN = 300 + 9;
LD dp[MAXN][MAXN];
int l,u,r,d;
LD get(int x, int y){
    if (l <= x && x <= r && u <= y && y <= d) return 0;
    return dp[x][y];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    int c = 0;
        cout << fixed;
        cout << setprecision(2);
    while(t--){
        c++;
        int n,m;
        cin >> n >> m >> l >> u >> r >> d;
        memset(dp,0,sizeof (dp));
        dp[1][1] = 1;
        LD ans = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if (i == 1 && j == 1) {
                    cout << dp[1][1] << ' ';
                    continue;
                }
                LD x = get(i, j -1);
                LD y = get(i - 1, j);
                if (j == m) dp[i][j] = y + .5*x;
                else if (i == n) dp[i][j] = .5*y + x;
                else dp[i][j] = .5L * y + .5L*x;
                if (l <= i && i <= r && u <= j && j <= d) ans -= dp[i][j];
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        if (l <= n && n <= r && u <= m && m <= d) ans = 0;
        if (dp[n][m] == 0) ans = 0;
        cout << "Case #" << c << ": " << ans << endl;  
    }
}