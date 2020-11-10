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
int const MAXN = 400;
LL dp[MAXN][MAXN];
int a[MAXN];
int n;
LL solve(int i, int time){
    if(i == n) return 0;
    if(time >= MAXN) return 1e18;
    LL& ret = dp[i][time];
    if(ret != -1) return ret;
    return ret = min(abs(time - a[i]) + solve(i + 1, time + 1), solve(i, time + 1));
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(dp, -1 ,sizeof(dp));
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        cout << solve(0,1) << endl;
    }
}