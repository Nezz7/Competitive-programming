#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 3e5 + 9;
LL dp[MAXN][4];
int a[MAXN], b[MAXN];
int n;
LL solve (int i , int add){
    if(i == n -1) return add * b[i];
    LL & ret = dp[i][add];
    if (ret != -1) return ret;
    ret = 1e18;
    for(int y = 0; y < 3; y++){
        if(a[i] + add == a[i + 1] + y) continue;
            ret = min(ret, add *1LL* b[i] + solve(i+1,y));
        }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i <= n; i++){
            dp[i][0] = dp[i][1] = dp[i][2] = -1;
        }
        for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
        LL ans = 1e18;
        for(int i = 0; i < 3; i++)
            ans = min(ans,solve(0,i));
        cout << ans << endl;
    }
}