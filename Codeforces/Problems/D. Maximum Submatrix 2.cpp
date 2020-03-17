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
int const MAXN = 5000 + 9;
int dp[MAXN][MAXN];
char a[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j] -= '0';
        }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j == 0) dp[j][i] = a[i][j];
            else {
                if (a[i][j]) dp[j][i] = dp[j-1][i] + 1; 
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++){
        sort(dp[j],dp[j]+n);
        for (int i = 0; i < n; i++){
            ans = max(ans,dp[j][i] *(n - i));
        }
    }
    cout << ans << endl;
   
}