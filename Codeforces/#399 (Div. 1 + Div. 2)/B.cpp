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
LL dp[60];
LL ans = 0;
void  get(LL x, LL start, LL end ){
    if(end < start) return;
    if(x <= 1){
        ans += x;
        return;
    }
    int m = x & 1;
    LL lg = log2(x/2);
    if(dp[lg] >= end){
        get(x/2, start, end);
        return;
    }
    if(start <= dp[lg] + 1 && dp[lg] + 1 <= end){
        ans += m;
    }
    if(start <= dp[lg]){
        get(x/2,start, min(end,dp[lg]));
        if(dp[lg] + 1 < end)
        get(x/2,1,end - dp[lg] - 1);
    }else if(start > dp[lg] + 1)
    get(x/2,start - dp[lg] - 1,end - dp[lg] - 1);
    else if(dp[lg] + 1 < end)
    get(x/2,1,end - dp[lg] - 1);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    dp[0] = 1;
    for(int i = 1; i < 60; i++) dp[i] = dp[i - 1] * 2 + 1;
    LL x, l, r;
    cin >> x >> l >> r;
    get(x,l,r);
    cout << ans << endl;
}