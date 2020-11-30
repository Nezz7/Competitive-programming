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
int dp[502][502][502];
int a[MAXN], n;
int solve(int i, int last, int x){
    if(i == n) return 0;
    int & ret = dp[i][last][x];
    if(ret != -1) return ret;
    ret = MAXN;
    if(last <= a[i]) ret = solve(i + 1, a[i], x);
    if(last <= x && a[i] > x) ret = min(ret,1 + solve(i + 1, x, a[i]));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> n >> x;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= 500; j++)
                for(int k = 0; k <= 500; k++)
                    dp[i][j][k] = -1;
        }
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int ans = solve(0,0,x);
        if(ans == MAXN) 
            ans = -1;
        cout << ans << endl;
    }

}