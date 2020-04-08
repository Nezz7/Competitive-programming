#include <bits/stdc++.h>
#define f first
#define s second
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
LL dp[MAXN][12];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n,m,k;
    cin >> n >> m >> k;
    LL a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL best = 0;
    for (int j = 0; j < m; j++) dp[0][j] = max(0LL,a[0] + (j == 0 ? -k : 0));
    best = max(dp[0][0],best);
    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            dp[i][j] = dp[i-1][(j + 1) % m] + a[i];
            if (j == 0) dp[i][j] -= k;
            dp[i][j] = max(dp[i][j],0LL);
        }
            best = max(best,dp[i][0]); 
    }
    cout << best;
}