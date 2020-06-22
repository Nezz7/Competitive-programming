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
 int const MAXN = 105;
 int occ[MAXN], a[MAXN];
 int p[2];
 int n;
 int dp[MAXN][3][MAXN][MAXN];
 int solve (int i, int last, int z , int o){
    if (i == n) return 0;
    int & ret = dp[i][last][z][o];
    if (ret != -1) return ret;
    ret = 1e9;
    if (a[i] == 0){
    if (o) {if (last == 0) ret = min(ret,1 + solve(i+1,1,z,o-1));
            else ret = min(ret,solve(i+1,1,z,o-1));}
    if (z) {if (last == 1) ret = min(ret,1 + solve(i+1,0,z-1,o));
            else ret = min(ret,solve(i+1,0,z-1,o));}
    }else {
        if (a[i]%2 != last && last != 2) ret =min(ret,1 + solve(i+1,a[i]%2,z,o));
        else ret = min(ret,solve(i+1,a[i]%2,z,o));
    }
    return ret;
 }
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i],occ[a[i]]++;
    for (int i = 1; i <= n; i++)
        if (!occ[i]) p[i%2]++;
    cout << solve (0,2,p[0],p[1]);
 }
