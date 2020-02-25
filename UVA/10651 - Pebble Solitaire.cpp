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
int dp[MAXN];
int solve (int mask){
   // cout << mask << endl;
    if (dp[mask] != -1) return dp[mask];
    dp[mask] = __builtin_popcount(mask);
    for (int i = 0; i < 10; i++){
        int a = mask & (1 << i);
        int b = mask & (1 << (i + 1));
        int c = mask & (1 << (i + 2));
        if (a && b && !c){
            int nxt = mask & (~(1 << i));
            nxt &= (~(1 << (i + 1)));
            nxt |=  (1 << (i + 2));
            dp[mask] = min(dp[mask],solve(nxt));
        }
        if (!a && b && c){
            int nxt = mask & (~(1 << (i + 2)));
            nxt &= (~(1 << (i + 1)));
            nxt |=  (1 << i);
            dp[mask] = min(dp[mask],solve(nxt));
        }
    }
    return dp[mask];
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    memset(dp,-1,sizeof dp);
    while (T--){
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < sz(s); i++){
            if (s[i] == 'o') mask |= (1 << i); 
        }
        cout << solve (mask) << endl;
    }
}