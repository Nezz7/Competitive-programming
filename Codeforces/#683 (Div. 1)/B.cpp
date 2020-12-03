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
int const MAXN = 5000 + 9;
int n, m;
string a,b;
int dp[MAXN][MAXN];
int solve(int i, int j){
    if(i == n or j == m) return 0;
    int& ret = dp[i][j];
    if(ret != -1) return ret;
    ret = 0;
    if(a[i] == b[j]) ret = max(ret, 2 + solve(i + 1, j + 1));
    return ret = max(ret, -1 + max(solve(i + 1, j), solve(i, j + 1)));
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << endl;
}