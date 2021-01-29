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
LL a[MAXN], b[MAXN], c[MAXN];
LL dp[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> c[i];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        LL ans = 0;
        for(int i = 1; i < n; i++){
            ans = max(c[i] + abs(a[i] - b[i]) + 1, ans);
        }
        dp[1] = abs(a[1] - b[1]);
        ans = max(dp[1] + c[1] + 1, ans);
        for(int i = 2; i < n; i++){
            if(a[i] == b[i]) dp[i] = 0;
            else dp[i] = c[i - 1] - abs(a[i] - b[i]) + dp[i - 1] + 1;
            ans = max(ans, dp[i] + c[i] + 1);
        }
        cout << ans << endl;
    }
}