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
 int const MAXN = 4000;
 int dp[MAXN][MAXN][3];
 int a[MAXN];
 int n, m,k,p;
 int get (int i, int j){
    int x = i + n -1 - j;
    if (x > k) return 0;
    return 1;
 }
 int solve (int i, int j,int c){
    if (i + n -1 - j == m -1){
            return max(a[i],a[j]);
    }
    int & ret = dp[i][j][c];
    if (ret != -1) return ret;
    if (i + n -1 - j >= k) return ret = min(solve(i+1,j,get(i+1,j)),solve(i,j-1,get(i,j-1)));
    else return ret = max(solve(i+1,j,get(i+1,j)),solve(i,j-1,get(i,j-1)));
 }

 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n >> m >> k;
        for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if  (m == 1) p = 1;
        else p = 0;
        cout << solve (0,n-1,p) << endl;;
    }
 }
