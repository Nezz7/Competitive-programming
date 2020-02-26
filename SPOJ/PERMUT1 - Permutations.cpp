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
int const MAXN = 14;
int n,k;
LL dp[MAXN][1 << MAXN][100];
LL solve (int pos , int mask, int l){
    if (l < 0) return 0;
    if (pos == n) if (l == 0) return 1;
                else return 0;
    LL & ret = dp[pos][mask][l];
    if (ret  != -1) return ret;
    ret = 0;
    int cur  = 0;
    for (int i = 0; i < n; i++){
        int bit = (mask & (1 << i)) >> i;
        if (bit == 0){
            ret += solve (pos+1, (mask | (1 << i)), l - cur );
            cur++;
        }
    }
    return ret;

}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        memset(dp,-1,sizeof dp);
        cin >> n >> k;
        cout << solve (0,0,k) << endl;
    }
}