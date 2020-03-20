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
int dp[MAXN][3];
int a[MAXN];
int k[3];
int n;
int solve (int i, int p){
    if (i == 1) return a[1] != p;
    int & ret = dp[i][p];
    if(ret != -1) return ret;
    ret = 1e9;
    if(a[i] == p) return ret = min(solve(i-1,p),min(solve(i-1,max(0,p-2)),solve(i-1,max(0,p-1))));
    return ret = min(solve(i-1,p),min(solve(i-1,max(0,p-2)),solve(i-1,max(0,p-1)))) + 1;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> k[0] >>k[1] >> k[2];
    n = k[0]+k[1]+k[2];
    for (int i = 0; i < k[0]; i++){
        int x;
        cin >> x;
        a[x] = 0;
    }
    for (int i = 0; i < k[1]; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 0; i < k[2]; i++){
        int x;
        cin >> x;
        a[x] = 2;
    }
    int ans = 1e9;
    for(int i = 0; i < 3; i++)
        ans = min(ans,solve(n,i));
    cout << ans << endl;

}