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
int n;
int a[MAXN][2];
LL dp[MAXN][4];
LL solve(int i, int last){
    if (i == n) return 0;
    LL & ret = dp[i][last];
    if( ~ ret ) return ret;
    ret = solve(i + 1, last);
    if(last == 1) ret = max(ret, a[i][0] + solve(i + 1, 0));
    if(last == 0) ret = max(ret, a[i][1] + solve(i + 1, 1));
    if(last == 2) ret = max(ret,max(a[i][1] + solve(i + 1, 1),a[i][0] + solve(i + 1, 0)));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
            cin >> a[i][0];
    }
    for(int i = 0; i < n; i++){
            cin >> a[i][1];
    }
    
    cout << solve(0,2) << endl;
}