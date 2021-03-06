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
 int const MAXN = 2e6 + 9;
 int const MOD = 1e9 + 7;
 LL dp[10][1005][1005];
 int n,m;
 LL solve (int i, int a, int b){
    if (a > n or b < 1 or a > b) return 0;
    if (i == m) return 1;
    LL & ret = dp[i][a][b];
    if (ret != -1) return ret;
    ret = solve (i+1, a, b);
    ret %= MOD;
    ret += solve (i, a+1, b);
    ret %= MOD;
    ret += solve (i, a, b-1);
    ret %=MOD;
    ret -= solve (i, a + 1,  b - 1);
    ret +=MOD;
    ret %=MOD;
    return  ret ;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cout << solve (0,1,n);
 }
