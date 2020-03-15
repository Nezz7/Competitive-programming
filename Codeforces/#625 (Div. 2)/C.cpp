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
int const MAXN = 100;
int dp[MAXN][MAXN][MAXN];
char mn[MAXN][MAXN];
string s;
int solve (int i, int l, int r){
    if (l > r) return 0;
    if (i < l or r < i) return 0;
    if (l == r) return 0;
    int & ret = dp[i][l][r];
    if (ret != -1) return ret;
    ret = 0;
    if (i != r){
        if (s[i] == s[i+1] + 1) ret = max(ret,1 + solve(i+1,l+1,r));
    }
    if (i != l){
        if (s[i] == s[i-1] + 1){
            int x = solve(i+1,i+1,r);
            int y = solve (l,l,i-1);
            if (x == r - i && y == i - l){
                ret = max (ret, 1 + x + y +(abs(mn[i+1][r] - mn[l][i-1]) == 1));
            }
            ret = max(1 + x + y,ret);
        }
        
         
    }
    ret = max(ret,solve(i+1,l,r));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    mn[i][j]= 'z';
    cin >> s;
    for (int l = 0; l < n; l++)
    for (int r = l; r < n; r++)
        for (int i = l; i <=r; i++)
        mn[l][r] = min(mn[l][r],s[i]);
    cout << solve(0,0,n-1) << endl;
    
}