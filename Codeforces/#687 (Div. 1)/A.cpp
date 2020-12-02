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
int dp[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, p, k;
        cin >> n >> p >> k;
        string s;
        cin >> s;
        LL x, y;
        cin >> x >> y;
        for(int i = 0; i < n; i++){
            dp[i] = s[i] == '0';
        }
        LL ans = 1e18;
        for(int i = n - 1; i > n - p - 1; i--){
            if(i + k < n) dp[i] += dp[i + k];
        }
        for(int i = n - p - 1; i >= 0; i--){
            if(i + k < n) dp[i] += dp[i + k];
            LL cur = y * (i + 1) + x * dp[i + p];
            ans = min(ans, cur); 
        }
        ans = min(ans, x * dp[p - 1]);
        cout << ans << endl;
    }
}