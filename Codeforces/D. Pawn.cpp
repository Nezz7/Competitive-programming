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
 int const MAXN = 100 + 9;
 int n, m, k;
 char a[MAXN][MAXN];
 int dp[MAXN][MAXN][1000];
 bool valid (int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
 }
 int solve (int i, int j, int sum){
    if (i == -1) if (sum%k) return - 1e9;
                 else return sum;
    int & ret = dp[i][j][sum];
    if ( ret != -1) return ret;
    int l, r;
    ret = l = r = -1e9;
    if (j + 1 < m ) r = solve(i-1,j+1,sum + a[i][j] - '0');
    if (j - 1 >= 0) l = solve(i-1,j-1,sum + a[i][j] - '0');
    if (i == 0) ret = solve(i-1,0,sum + a[i][j] - '0');
    return ret = max({r,l,ret});
 }
 int ans;
 void print (int i, int j,int sum){
    if (i == 0) return;
    int l, r;
    l = r = -1e9;
    if (j + 1 < m ) r = solve(i-1,j+1,sum + a[i][j] - '0');
    if (j - 1 >= 0) l = solve(i-1,j-1,sum + a[i][j] - '0');
    if (ans == r){
        cout << "R";
        print(i-1,j+1,sum+a[i][j]-'0');
        return;
    }
    if (ans == l){
        cout << "L";
        print(i-1,j-1,sum+a[i][j]-'0');
        return;
    }
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m >> k;
    k++;
    memset(dp,-1,sizeof dp);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
   ans = -1e9;
  for (int i = 0; i <m; i++)
    ans = max(ans,solve(n-1,i,0));
    if (ans == -1e9)  cout << -1;
    else {
        cout << ans << endl;
        for (int i = 0; i <m; i++){
            if (ans == solve(n-1,i,0)){
                cout << i+1 << endl;
                print(n-1,i,0);
                break;
            }
        }
    }
 }
