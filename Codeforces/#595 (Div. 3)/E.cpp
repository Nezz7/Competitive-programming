 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define int long long
 #define pb push_back
 #define sz(a) (int)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 using namespace std;
 int const MAXN = 2e6 + 9;
 int dp[MAXN][3];
 int32_t main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, c;
    cin >> n >> c;
    int  a[n];
    int  b[n];
    for (int i = 0; i < n-1; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) cin >> b[i];
    dp[0][0] = 0;
    dp[0][1] = 1e9;
    for (int i = 0; i < n -1; i++){
        dp[i+1][0] = min(dp[i][0],dp[i][1]) + a[i];
        dp[i+1][1] = min(dp[i][0] + c + b[i],dp[i][1] + b[i]);
    }
    for (int i  = 0; i < n; i++) cout << min(dp[i][0],dp[i][1]) << " ";

 }
