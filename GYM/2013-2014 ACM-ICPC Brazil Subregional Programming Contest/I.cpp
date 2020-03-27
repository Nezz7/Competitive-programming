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
int const MAXN = 3000 + 9;
int dp[MAXN][3];
int n,c,a,b;
int x[MAXN];
int start;
int solve(int i, bool cond){
    cout << i << " " << x[i] << " " << cond << endl;
    if (i == start && cond) return 0;
    int & ret = dp[i][cond];
    if(ret != -1) return ret;
    ret = 1e9;
    int nxt = lower_bound(x,x+n,(x[i]+ a + 1)%c)- x;
    if((x[i]+ a + 1) >= c){
        if(nxt >= start) nxt = start;
    }
    if(nxt == n) nxt =0;
    ret = a + solve(nxt,1);
    nxt = lower_bound(x,x+n,(x[i]+ b + 1)%c)- x;
    if((x[i]+ b + 1) >= c){
        if(nxt >= start) nxt = start;
    }
    if(nxt == n) nxt =0;
    ret = min(ret,b + solve(nxt,1));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> c >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int ans = 1e9;
    for(int i = 0; i <n  ;i++){
        memset(dp,-1,sizeof dp);
        start = i;
        ans = min(ans,solve(i,0));
    }
        cout << " ANS " <<ans;
}