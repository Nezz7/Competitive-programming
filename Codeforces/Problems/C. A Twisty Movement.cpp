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
int dp[MAXN][5];
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][a[0] - 1] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0 ; j < 4; j++){
            if(a[i] == 1){
                if(j == 0 or j == 2)
                    dp[i][j] = max(dp[i- 1][max(j - 1, 0)],dp[i - 1][j]) + 1;
                else dp[i][j] = dp[i - 1][j];
                
            }else {
                if(j == 1 or j == 3)
                    dp[i][j] = max(dp[i - 1][max(j - 1,0)],dp[i - 1][j]) + 1;
                else dp[i][j] = dp[i - 1][j];
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans << endl;
}