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
int dp[MAXN][MAXN];
string s;
int n;
int solve (int i, int l){
    
    if ( i == n) return 0;
    int & ret = dp[i][l];
    if (ret != -1) return ret;
    ret = 0;
    if (i + l + 1< n ){
        if (s[i] == s[i+l + 1] + 1) ret = max(ret,1 + max(solve(i+1,l+1),solve(i-l-1,l+1)));
    }
    if (i - l - 1 >= 0 ){
        if (s[i] == s[i- l -1] + 1) ret = max(ret,1 + max(solve(i+1,l+1),solve(i-l-1,l+1)));
    }
    ret = max(ret,solve(i+1,0));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    cin >> s;
    int ans  = 0;
    for (int i = 0; i < n; i++){
        memset(dp,-1,sizeof dp);
        ans = max(ans,solve(i,0));
    }
    cout << ans << endl;
    
}