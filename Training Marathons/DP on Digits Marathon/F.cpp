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
int n,m;
int a[20];
int dp[20][20];
int solve (int pos, int last){
    if (pos == n) return 1;
    int & ret = dp[pos][last];
    if (ret != -1) return ret;
    ret = 0;
    if (pos == 0){
        for (int i= 0; i < m; i++){
            ret += solve(pos+1,a[i]);
         } 
    }else {
        for (int i= 0; i < m; i++){
            if (abs(last - a[i]) <= 2) ret += solve(pos+1,a[i]);
        } 
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int c = 0;
    while (T--){
        c++;
        int ans = 0;
        memset(dp,-1,sizeof dp);
        cin >> m >> n;
        for (int i = 0; i < m; i++) 
            cin >> a[i];
        ans += solve (0,0);
        cout << "Case " << c << ": ";
        cout << ans << endl;
    }
}