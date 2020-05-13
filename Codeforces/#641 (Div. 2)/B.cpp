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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n + 9; i++) dp[i] = 1;
        for(int i = n; i >= 1; i--){
            for(LL j = 1; j * j <= i; j++){
                if(i % j == 0){
                    if (a[i] > a[j]) 
                        dp[j] = max(dp[j], 1 + dp[i]);
                    int k = i / j;
                    if (a[i] > a[k]) 
                        dp[k] = max(dp[k], 1 + dp[i]);
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans,dp[i]);
        cout << ans << endl;
    }
}