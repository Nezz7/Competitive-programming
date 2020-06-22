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
int const MAXN = 3000 + 9;
int n,h,l,r;
int dp[MAXN][MAXN];
int a[MAXN];
int solve (int i,int x){
    if (i == n) return 0;
    int & ret = dp[i][x];
    if (ret != -1) return ret;
    ret = 0;
    int p1 = (x + a[i]) % h;
    int p2 = (x + a[i] - 1+ h) % h;
    ret = max(ret,solve(i+1,(x + a[i])%h) + (p1 >= l && p1 <= r));
    ret = max(ret,solve(i+1,(x + a[i] - 1 + h)%h) + (p2 >= l && p2 <= r));
    return ret;

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> h >> l >> r;

    memset(dp,-1,sizeof dp);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0,0);
}